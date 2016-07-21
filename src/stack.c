#include "stack.h"

Stack create_stack() {
    Stack s;
    s = create_list();
    return s;
}

void delete_stack(Stack s) {
    delete_list(s);
}

void push(ElementType x, Stack s) {
    insert(x, s, s);
}

void pop(Stack s) {
    Node n;
    n = s->next;
    s->next = n->next;
    free(n);
}

ElementType top(Stack s) {
    Node n;
    n = s->next;
    if (n != NULL) {
        return n->element;
    }
    return 0;
}
