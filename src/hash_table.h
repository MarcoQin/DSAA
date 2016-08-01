#ifndef __HASH_TABLE_H
#define __HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *key;
    void *value;
} DictEntry;

typedef struct _dictobject DictObject;
struct _dictobject {
    long ma_fill;  /* Active + Dummy */
    long ma_used; /* Active */
    long ma_size; /* table size */

    DictEntry *ma_table;
};

DictObject * Dict_New (int table_size);
DictEntry * lookup(DictObject *d, const char *key);
void dict_set_item(DictObject *d, const char *key, void *value);
int dict_del_item(DictObject *d, const char *key, void **out);
void destroy_dict(DictObject *d);

#endif /* ifndef __HASH_TABLE_H */
