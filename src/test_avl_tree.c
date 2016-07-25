#include "avl_tree.h"
#include "unittest.h"
#include <assert.h>


static AvlTree T = NULL;

char *test_delete() {
    T = make_empty(T);
    mu_assert(T == NULL, "make_empty Error!");
    return NULL;
}

char *test_insert() {
    for (int i = 1; i < 80; i++) {
        T = insert(i, T);
    }
    print_ascii_tree(T);
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_insert);
    mu_run_test(test_delete);
    return NULL;
}

RUN_TESTS(all_tests);
