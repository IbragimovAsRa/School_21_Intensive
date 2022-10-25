#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <stdio.h>
#include <stdlib.h>

union Data {
    double num;
    char symb;
    char cmnd[5];
};

struct node {
    int type;
    union Data data;
    struct node *next;
};

struct node* init(int type, const union Data* data);
struct node* add_node(struct node* elem, int type, union Data* data);
void destroy(struct node* root);
void output(struct node* root);
int count_node(struct node* root);

#endif  // SRC_LIST_H_
