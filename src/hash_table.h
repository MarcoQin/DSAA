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

#endif /* ifndef __HASH_TABLE_H */
