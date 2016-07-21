#include "link_list.h"
#include "dbg.h"

List create_list() {
    List l = malloc(sizeof(struct _Node));
    return l;
}

int is_empty(List L) {
    return L->next == NULL;
}

int is_last(Node node) {
    return node->next == NULL;
}

Node find(ElementType x, List L) {
    Node node;
    node = L->next;
    while (node != NULL && node->element != x) {
        node = node->next;
    }
    return node;
}

Node find_previous(ElementType x, List L) {
    Node node;
    node = L;
    while (node->next != NULL && node->next->element != x) {
        node = node->next;
    }
    return node;
}

void delete(ElementType x, List L) {
    Node node, tmp_cell;
    node = find_previous(x, L);
    if (!is_last(node)) {
        tmp_cell = node->next;
        node->next = tmp_cell->next;
        free(tmp_cell);
    }
}

void insert(ElementType x, List L, Node position) {
    Node tmp_cell;
    tmp_cell = malloc(sizeof(struct _Node));
    if (tmp_cell == NULL) {
        fprintf(stderr, "Error! Cannot alloc memory!\n");
        exit(1);
    }
    tmp_cell->element = x;
    tmp_cell->next = position->next;
    position->next = tmp_cell;
}

void delete_list(List L) {
    Node node, tmp_cell;
    node = L->next;
    L->next = NULL;
    while (node != NULL) {
        tmp_cell = node->next;
        debug("node != NULL %d", node->element);
        free(node);
        debug("free node");
        node = tmp_cell;
        debug("node = tmp_cell");
    }
    debug("success Free all nodes");
    free(L);
}
