#include "hash_table.h"


long hash(const char *key, int table_size) {
    long hash_val = 0;
    while (*key != '\0') {
        hash_val = (hash_val << 5) + *key++;
    }
    return hash_val % table_size;
}
