#include "queue.h"
#include "unittest.h"
#include <assert.h>

static Queue queue = NULL;

ElementType test1 = 10;
ElementType test2 = 20;
ElementType test3 = 30;

char *test_create() {
    queue = create_queue();
    mu_assert(queue!= NULL, "Failed to create queue.");
    return NULL;
}

char *test_delete_queue() {
    delete_queue(queue);
    return NULL;
}

char *test_enqueue_dequeue() {
    enqueue(test1, queue);
    enqueue(test2, queue);
    enqueue(test3, queue);
    mu_assert(dequeue(queue) == test1, "dequeue1 Error!");
    mu_assert(dequeue(queue) == test2, "dequeue2 Error!");
    mu_assert(dequeue(queue) == test3, "dequeue3 Error!");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_create);
    mu_run_test(test_enqueue_dequeue);
    mu_run_test(test_delete_queue);
    return NULL;
}

RUN_TESTS(all_tests);
