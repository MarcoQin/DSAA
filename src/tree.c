#include "tree.h"
#include "dbg.h"

SearchTree make_empty(SearchTree T) {
    if (T != NULL) {
        make_empty(T->left);
        make_empty(T->right);
        free(T);
    }
    return NULL;
}

TreeNode find(ElementType x, SearchTree T) {
    if (T == NULL) {
        return NULL;
    }
    if (x < T->element) {
        return find(x, T->left);
    } else if (x > T->element) {
        return find(x, T->right);
    } else {
        return T;
    }
}



TreeNode find_min(SearchTree T) {
    if (T != NULL) {
        while(T->left != NULL) {
            T = T->left;
        }
    }
    return T;
}

TreeNode find_max(SearchTree T) {
    if (T != NULL) {
        while(T->right != NULL) {
            T = T->right;
        }
    }
    return T;
}

SearchTree insert(ElementType x, SearchTree T) {
    if (T == NULL) {
        T = malloc(sizeof(struct _TreeNode));
        check_mem(T);
        T->element = x;
        T->left = T->right = NULL;
    } else {
        if (x < T->element) {
            T->left = insert(x, T->left);
        } else if (x > T->element) {
            T->right = insert(x, T->right);
        }
    }
    return T;
error:
    exit(1);
}

SearchTree delete(ElementType x, SearchTree T) {
    TreeNode tmp_cell;
    if (T == NULL) {
        log_err("Element not found!");
    } else {
        if (x < T->element) {
            T->left = delete(x, T->left);
        } else if (x > T->element) {
            T->right = delete(x, T->right);
        } else if (T->left && T->right) {
            tmp_cell = find_min(T->right);
            T->element = tmp_cell->element;
            T->right = delete(x, T->right);
        } else {
            tmp_cell = T;
            if (tmp_cell->left == NULL) {
                T = tmp_cell->right;
            } else if (tmp_cell->right == NULL) {
                T = tmp_cell->left;
            }
            free(tmp_cell);
        }
    }
    return T;
}

int width = 1280 / 2 / 2 / 2 / 2;

void print_name(ElementType x, int depth, int left) {
    int i = 0;
    if (depth == 0) {
        for (i = 0; i < width; i++) {
            fprintf(stderr, " ");
        }
    } else if (left){
        for (i = 0; i < (width - 10 * depth); i++) {
            fprintf(stderr, " ");
        }
    } else {
        for (i = 0; i < (width + 10 * depth); i++) {
            fprintf(stderr, " ");
        }
    }
    fprintf(stderr, "%d\n", x);
}

void print_tree(SearchTree T, int depth, int left) {
    if (T != NULL) {
        /* fprintf(stderr, "Node->%d\n", T->element); */
        print_name(T->element, depth, left);
        print_tree(T->left, depth + 1, 1);
        print_tree(T->right, depth + 1, 0);
    }
}
