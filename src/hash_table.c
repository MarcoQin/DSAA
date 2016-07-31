#include "hash_table.h"
#include "dbg.h"
#define MIN_DICT_SIZE = 10

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

    for(i = 0; i < dict->table_size; i++) {
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
            freeslot == ep;
    }
    return NULL;
}
