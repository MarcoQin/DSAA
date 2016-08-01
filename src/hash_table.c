#include "hash_table.h"
#include "dbg.h"
#define MIN_DICT_SIZE 10

const char *dummy = "dummy";


long hash(const char *key, int table_size) {
    long hash_val = 0;
    while (*key != '\0') {
        hash_val = (hash_val << 5) + *key++;
    }
    return hash_val % table_size;
}

static int next_prime(int n) {
    int i;
    if (n % 2 == 0)
        n++;
    for (; ; n+=2) {
        for (i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                goto count_outer;
        }
        return n;
count_outer: ;
    }
}

DictObject * Dict_New (int table_size) {
    DictObject *dict;
    int i;
    if (table_size < MIN_DICT_SIZE)
        table_size = MIN_DICT_SIZE;
    dict = malloc(sizeof(DictObject));
    check_mem(dict);
    dict->ma_size = next_prime(table_size);
    dict->ma_fill = 0;
    dict->ma_used = 0;

    dict->ma_table = malloc(sizeof(DictObject) * dict->ma_size);
    check_mem(dict->ma_table);

    for(i = 0; i < dict->ma_size; i++) {
        dict->ma_table[i].key = NULL;
        dict->ma_table[i].value = NULL;
    }
    return dict;

error:
    exit(1);
}


DictEntry * lookup(DictObject *d, const char *key) {
    long i;
    long size = d->ma_size;
    i = hash(key, (int)size);
    long collision = 0;
    DictEntry *ep0 = d->ma_table;
    DictEntry *ep;
    DictEntry *freeslot;
    ep = &ep0[i];
    if (ep->key == NULL || ep->key == key) {
        return ep;
    }
    if (ep->key == dummy) {
        freeslot = ep;
    }
    for (int j = 0;j < size; j++) {
        i += 2 * ++collision - 1;
        ep = &ep0[i];
        if (ep->key == NULL)
            return freeslot == NULL ? ep : freeslot;
        if (ep->key == key)
            return ep;
        if (ep->key == dummy && freeslot == NULL)
            freeslot = ep;
    }
    return NULL;
}

int insert_dict(DictObject *d, const char *key, void *value);

void dictresize(DictObject *d, int size) {
    DictEntry *old_dict, *ep;
    int i, old_size;
    old_dict = d->ma_table;
    old_size = d->ma_size;
    d = Dict_New(size);
    for (i = 0; i < old_size; i++) {
        ep = &old_dict[i];
        if (ep->key != NULL && ep->key != dummy) {
            insert_dict(d, ep->key, ep->value);
        }
    }
    free(old_dict);
}

int insert_dict_by_entry(DictObject *d, const char *key, DictEntry *ep, void *value) {
    void *old_value;
    if (ep->value == NULL) {
        old_value = ep->value;
        ep->value = value;
        free(old_value);
    } else {
        if (ep->key == NULL) {
            d->ma_fill++;
        } else {
            if (ep->key != dummy) {
                log_err("Error! ep->key != dummy!");
                exit(1);
            }
        }
        ep->key = key;
        ep->value = value;
        d->ma_used++;
    }
    return 0;
}

int insert_dict(DictObject *d, const char *key, void *value) {
    DictEntry *ep;
    ep = lookup(d, key);
    if (ep == NULL) {
        free(value);
        log_err("Fail to insert dict!");
        return -1;
    }
    return insert_dict_by_entry(d, key, ep, value);
}

void dict_set_item(DictObject *d, const char *key, void *value) {
    long n_used = d->ma_used;
    insert_dict(d, key, value);
    if (d->ma_used > n_used && d->ma_fill * 3 >= d->ma_size * 2)
        dictresize(d, (d->ma_used > 50000 ? 2 : 4) * d->ma_used);
}


int dict_del_item(DictObject *d, const char *key, void **out) {
    DictEntry *ep;
    ep = lookup(d, key);
    if (ep == NULL)
        return -1;
    if (ep->value == NULL)
        return -1;
    *out = ep->value;
    ep->value = NULL;
    ep->key = dummy;
    d->ma_used--;
    return 0;
}

void destroy_dict(DictObject *d) {
    if (d == NULL)
        return;
    free(d->ma_table);
    free(d);
}
