#include "tree.h"
#include "unittest.h"
#include <assert.h>


static SearchTree T = NULL;

char *test_delete() {
    T = make_empty(T);
    return NULL;
}

char *test_insert() {
    int arr[] = {5, 3, 7, 8, 2, 1, 6, 8, 9, 11, 20, 32, 4, 13};
    for (int i = 0; i < 14; i++) {
        T = insert(arr[i], T);
    }
    /* print_tree(T, 0, 0); */
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
