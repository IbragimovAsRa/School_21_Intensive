#include "list.h"

// list functions

struct node* init(int type, const union Data* data) {
    struct node *elem = malloc(sizeof(struct node));
    elem->type = type;
    elem->data = *data;
    elem->next = NULL;
    return elem;
}

struct node* add_node(struct node* elem, int type, union Data* data) {
    struct node* new_elem = init(type, data);
    if (elem != NULL && elem->next != NULL) {
        new_elem->next = elem->next;
    }
    if (elem != NULL) {
        elem->next = new_elem;
    }
    return new_elem;
}

void destroy(struct node* root) {
    struct node* prev = root;
    while (root != NULL) {
        root = root->next;
        free(prev);
        prev = root;
    }
}

// void output(struct node* root) {
//     if (root == NULL) printf("NULL");
//     while (root != NULL && root->type != 0) {
//         printf("type %d. ", root->type);
//         if (root->type == 1) {
//             printf("%.2lf\n", root->data.num);
//         } else if (root->type == 2 || root->type == 4 || root->type == 5) {
//             printf("%c\n", root->data.symb);
//         } else if (root->type == 3) {
//             printf("%s\n", root->data.cmnd);
//         }
//         root = root->next;
//     }
//     printf("\n");
// }

int count_node(struct node* root) {
    int counter = 0;
    while (root != NULL && root->type != 0) {
        counter++;
        root = root->next;
    }
    return counter;
}
