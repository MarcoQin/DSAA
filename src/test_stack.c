#include "stack.h"
#include "unittest.h"
#include <assert.h>

static Stack stack = NULL;

ElementType test1 = 10;
ElementType test2 = 20;
ElementType test3 = 30;

char *test_create() {
    stack = create_stack();
    mu_assert(stack != NULL, "Failed to create stack.");
    return NULL;
}

char *test_delete_stack() {
    debug("start delete_stack");
    delete_stack(stack);
    debug("finish delete_stack");
    return NULL;
}

char *test_push_top_pop() {
    push(test1, stack);
    push(test2, stack);
    push(test3, stack);
    mu_assert(top(stack) == test3, "top Error!");
    pop(stack);
    mu_assert(top(stack) == test2, "pop and top Error!");
    pop(stack);
    mu_assert(top(stack) == test1, "pop and top Error!");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_push_top_pop);
    mu_run_test(test_delete_stack);
    return NULL;
}

RUN_TESTS(all_tests);
