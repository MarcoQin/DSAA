#ifndef __STACK_H
#define __STACK_H
#include "link_list.h"
typedef List Stack;

Stack create_stack();
void delete_stack(Stack s);
void push(ElementType x, Stack s);
ElementType top(Stack s);
void pop(Stack s);

#endif /* ifndef __STACK_H */
