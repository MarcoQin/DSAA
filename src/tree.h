#ifndef __TREE_H
#define __TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct _TreeNode
{
    ElementType element;
    struct _TreeNode *left;
    struct _TreeNode *right;
};

typedef struct _TreeNode* TreeNode;
typedef TreeNode Tree;
typedef TreeNode SearchTree;

SearchTree make_empty(SearchTree T);
TreeNode find(ElementType x, SearchTree T);
TreeNode find_min(SearchTree T);
TreeNode find_max(SearchTree T);
SearchTree insert(ElementType x, SearchTree T);
SearchTree delete(ElementType x, SearchTree T);
ElementType retrieve(TreeNode node);
void print_tree(SearchTree T, int depth, int left);

#endif /* ifndef __TREE_H */
