#include "link_list.h"
#include "unittest.h"
#include <assert.h>

static List list = NULL;

ElementType test1 = 10;
ElementType test2 = 20;
ElementType test3 = 30;

char *test_create() {
    list = create_list();
    mu_assert(list != NULL, "Failed to create list.");
    return NULL;
}

char *test_delete_list() {
    debug("start delete_list");
    delete_list(list);
    debug("finish delete_list");
    return NULL;
}

char *test_insert_find() {
    insert(test1, list, list);
    insert(test2, list, list);
    insert(test3, list, list);
    Node node = NULL;
    node = find(test3, list);
    mu_assert(node->element == test3, "Find test3 Error!");
    mu_assert(node->next->element == test2, "Find test2 Error!");
    mu_assert(node->next->next->element == test1, "Find test 1 Error!");
    return NULL;
}

char *test_delete_node() {
    delete(test2, list);
    Node node = NULL;
    node = find(test3, list);
    mu_assert(node->next->element == test1, "Failed to delete");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_insert_find);
    mu_run_test(test_delete_node);
    mu_run_test(test_delete_list);
    return NULL;
}

RUN_TESTS(all_tests);
