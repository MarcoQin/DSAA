#include "hash_table.h"
#include "unittest.h"
#include <assert.h>

DictObject *dict;

char *test_create() {
    dict = Dict_New(10);
    mu_assert(dict != NULL, "init Error!");
    return NULL;
}

char *test_insert() {
    const char *key = "name";
    const char *value = "hash_table";
    dict_set_item(dict, key, (void *)value);
    return NULL;
}

char *test_find() {
    const char *key = "name";
    const char *value = "hash_table";
    DictEntry *ep = lookup(dict, key);
    const char *r_value = (const char *)ep->value;
    log_info("result value is: %s", r_value);
    mu_assert(r_value == value, "find error!");
    return NULL;
}

char *test_delete() {
    const char *key = "name";
    char *value;
    int r = dict_del_item(dict, key, (void **)&value);
    log_info("%s", value);
    mu_assert(r == 0, "Delete error");
    return NULL;
}

char *test_destory() {
    destroy_dict(dict);
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_insert);
    mu_run_test(test_find);
    mu_run_test(test_delete);
    mu_run_test(test_destory);
    return NULL;
}

RUN_TESTS(all_tests);
