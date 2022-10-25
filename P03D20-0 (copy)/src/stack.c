#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack_sym *init_sym(char *value) {
    stack_sym *head = malloc(sizeof(stack_sym));
    head->value = value;
    head->next = NULL;
    return head;
}

void push_sym(stack_sym **head, char *value) {
    stack_sym *temp = malloc(sizeof(stack_sym));
    temp->next = *head;
    temp->value = value;
    *head = temp;
}

char *pop_sym(stack_sym **head) {
    stack_sym *temp;
    char *value;
    temp = *head;
    *head = (*head)->next;
    value = temp->value;
    free(temp);
    return value;
}

void destroy_sym(stack_sym **head) {
    stack_sym *temp = NULL;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

stack_num *init_num(double value) {
    stack_num *head = malloc(sizeof(stack_num));
    head->value = value;
    head->next = NULL;
    return head;
}

void push_num(stack_num **head, double value) {
    stack_num *temp = malloc(sizeof(stack_num));
    temp->value = value;
    temp->next = *head;
    (*head) = temp;
}

double pop_num(stack_num **head) {
    stack_num *temp;
    double value;
    temp = *head;
    *head = (*head)->next;
    value = temp->value;
    free(temp);
    return value;
}

// void destroy_num(stack_num **head) {
//    stack_num *temp = NULL;
//    while (*head != NULL) {
//        temp = *head;
//        *head = (*head)->next;
//        free(temp);
//    }
//}
//
//
// int getSize(stack_num **head) {
//    int size = 0;
//    while ((*head) != NULL) {
//        size++;
//        *head = (*head)->next;
//    }
//    return size;
//}
