#ifndef __LINK_LIST_H
#define __LINK_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct _Node
{
    ElementType element;
    struct _Node* next;
};
typedef struct _Node *List;
typedef struct _Node *Node;

List create_list();
List make_empty(List L);
int is_empty(List L);
int is_last(Node node);
Node find(ElementType x, List L);
void delete(ElementType x, List L);
Node find_previous(ElementType x, List L);
void insert(ElementType x, List L, Node position);
void delete_list(List L);
Node header(List L);
Node first(List L);

#endif /* ifndef __LINK_LIST_H */
