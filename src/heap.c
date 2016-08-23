#include "heap.h"
#include "dbg.h"

#define MinHeapSize 10
#define MinData -32767

Heap initialize(int max_elements) {
    Heap H;

    if (max_elements < MinHeapSize) {
        fprintf(stderr, "Heap size is too small\n");
        exit(1);
    }

    H = malloc(sizeof(struct _Heap));
    check_mem(H);
    H->elements = malloc((max_elements + 1) * sizeof(ElementType));
    check_mem(H->elements);
    H->capacity = max_elements;
    H->size = 0;
    H->elements[0] = MinData;

    return H;
error:
    exit(1);
}

void make_empty(Heap H) {
    H->size = 0;
}

int is_full(Heap H) {
    return H->size == H->capacity;
}

int is_empty(Heap H) {
    return H->size == 0;
}

void destroy(Heap H) {
    free(H->elements);
    free(H);
}

void insert(Heap H, ElementType X) {
    int i;
    check(!is_full(H), "Heap is Full");
    for (i = ++H->size; H->elements[i / 2] > X; i /= 2) {
        H->elements[i] = H->elements[i / 2];
    }
    H->elements[i] = X;
error:
    return;
}

ElementType delete_min(Heap H) {
    int i, child;
    ElementType min_element, last_element;
    check(!is_empty(H), "Heap is empty");
    min_element = H->elements[1];
    last_element = H->elements[H->size--];

    for (i = 1; i * 2 <= H->size; i = child) {
        child = i * 2;
        if (child != H->size && H->elements[child + 1] < H->elements[child]) {
            child++;
        }
        if (last_element > H->elements[child]) {
            H->elements[i] = H->elements[child];
        } else {
            break;
        }
    }
    H->elements[i] = last_element;
    return min_element;
error:
    return H->elements[0];
}
