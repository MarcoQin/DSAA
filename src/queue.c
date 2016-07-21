#include "queue.h"
#include "dbg.h"

Queue create_queue() {
    Queue q = malloc(sizeof(struct _Queue));
    q->data = malloc(sizeof(struct _Node));
    q->front = q->data;
    q->rear = q->data;
    q->size = 0;
    return q;
}

int is_empty(Queue q) {
    return q->size == 0;
}

void enqueue(ElementType x, Queue q) {
    Node rear = q->rear;
    Node new = malloc(sizeof(struct _Node));
    new->element = x;
    rear->next = new;
    q->rear = new;
    if (is_empty(q)) {
        q->front = new;
    }
    q->size++;
}

ElementType dequeue(Queue q) {
    if (is_empty(q)) {
        log_err("empty queue!!");
        return 0;
    }
    Node front = q->front;
    ElementType rt = front->element;
    q->front = q->front->next;
    free(front);
    if (q->size == 1) {
        q->rear = q->data;
    }
    q->size--;
    return rt;
}


void make_empty(Queue q) {
    while (q->size != 0) {
        dequeue(q);
    }
}

void delete_queue(Queue q) {
    make_empty(q);
    free(q->data);
    free(q);
}
