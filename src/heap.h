#ifndef __HEAP_H
#define __HEAP_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct _Heap {
    int capacity;
    int size;
    ElementType *elements;
};

typedef struct _Heap *Heap;

Heap initialize(int max_elements);
void destroy(Heap H);
void make_empty(Heap H);
void insert(Heap H, ElementType X);
ElementType delete_min(Heap H);
ElementType find_min(Heap H);
int is_empty(Heap H);
int is_full(Heap H);

#endif /* ifndef __HEAP */
