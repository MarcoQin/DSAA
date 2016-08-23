#include "heap.h"
#include "unittest.h"
#include <assert.h>

static Heap heap = NULL;

char *test_create() {
    heap = initialize(20);
    mu_assert(heap != NULL, "Failed to create heap");
    return NULL;
}

char *test_insert() {
    int i;
    for (i = 0; i < 15; i++) {
        insert(heap, i);
    }
    return NULL;
}

char *test_delete_min() {
    int i, element;
    for (i = 0; i < 15; i++) {
        element = delete_min(heap);
        mu_assert(element == i, "Delete Min Failed");
    }
    return NULL;
}

char *test_destroy() {
    destroy(heap);
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_insert);
    mu_run_test(test_delete_min);
    mu_run_test(test_destroy);
    return NULL;
}

RUN_TESTS(all_tests);
