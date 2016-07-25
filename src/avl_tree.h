#ifndef __AVL_TREE_H
#define __AVL_TREE_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct _AvlNode {
    ElementType element;
    struct _AvlNode *left;
    struct _AvlNode *right;
    int height;
};
typedef struct _AvlNode *AvlNode;
typedef AvlNode AvlTree;

AvlTree make_empty(AvlTree T);
AvlNode find(ElementType x, AvlTree T);
AvlNode find_min(AvlTree T);
AvlNode find_max(AvlTree T);
AvlTree insert(ElementType x, AvlTree T);
AvlTree delete(ElementType x, AvlTree T);
ElementType retrieve(AvlNode node);

#endif /* ifndef __AVL_TREE_H */
