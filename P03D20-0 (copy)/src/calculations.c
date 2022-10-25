#include "stack.h"
#include "list.h"
#include <string.h>
#include "calculations.h"
#include <math.h>
#include <stdio.h>

double calculate_polish_notation(struct node *list, int length, double number) {
    stack_num *stack = init_num(0);
    for (int i = 0; i < length; i++) {
        if (list->type == 1) {
            push_num(&stack, list->data.num);
        } else if (list->type == 3) {
            double result = calculator_helper(list, stack);
            push_num(&stack, result);
        } else if (list->type == 2) {
            double num = number;
            push_num(&stack, num);
        }
        list = list->next;
    }
    double res = pop_num(&stack);
    return res;
}

double calculator_helper(struct node *list, stack_num *stack) {
    double num1 = pop_num(&stack);
    double result = 0;
    double num2 = 0;
    if (check_operation(list->data.cmnd[0])) {
        num2 = pop_num(&stack);
    }
    if (list->data.cmnd[0] == '+') {
        result = num2 + num1;
    } else if (list->data.cmnd[0] == '-') {
        result = num2 - num1;
    } else if (list->data.cmnd[0] == '*') {
        result = num2 * num1;
    } else if (list->data.cmnd[0] == '/') {
        if (num1 == 0) {
            result = -1;
        } else {
            result = num2 / num1;
        }
    } else if (strcmp(list->data.cmnd, "sin  ") == 0) {
        result = sin(num1);
    } else if (strcmp(list->data.cmnd, "cos  ") == 0) {
        result = cos(num1);
    } else if (strcmp(list->data.cmnd, "tan  ") == 0) {
        result = tan(num1);
    } else if (strcmp(list->data.cmnd, "ctg  ") == 0) {
        result = 1 / tan(num1);
    } else if (strcmp(list->data.cmnd, "ln   ") == 0) {
        result = log(num1);
    } else if (strcmp(list->data.cmnd, "exp  ") == 0) {
        result = exp(num1);
    } else if (strcmp(list->data.cmnd, "sqrt ") == 0) {
        result = sqrt(num1);
    } else if (strcmp(list->data.cmnd, "~    ") == 0) {
        result = -num1;
    }
    return result;
}

int check_operation(char comm) {
    int flag = 0;
    if (comm == '+' || comm == '-' || comm == '*' || comm == '/') {
        flag = 1;
    }
    return flag;
}
