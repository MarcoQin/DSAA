#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct _Node {
    ElementType element;
    struct _Node *next;
    struct _Node *previous;
};

typedef struct _Node *Node;
typedef Node List;
struct _Queue {
    Node front;
    Node rear;
    int size;
    List data;
};
typedef struct _Queue *Queue;

int is_empty(Queue q);
Queue create_queue();
void make_empty(Queue q);
void delete_queue(Queue q);
void enqueue(ElementType x, Queue q);
ElementType dequeue(Queue q);

#endif /* ifndef __QUEUE_H */
