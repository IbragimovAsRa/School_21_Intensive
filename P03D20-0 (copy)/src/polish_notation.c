#include "stack.h"
#include "list.h"
#include <string.h>
#include "polish_notation.h"

struct node *parse_list(struct node *list, int length) {
    struct node *postfix_list = NULL, *result = NULL;
    int flag = 0, flag1 = 1;
    stack_sym *stack = init_sym("#");
    for (int i = 0; i < length; i++) {
        union Data data;
        if (compare_helper(list) == 1) {
            data.num = list->data.num;
            postfix_list = add_node(postfix_list, 1, &data);
            flag = 1;
        }
        if (compare_helper(list) == 2) {
            data.symb = list->data.symb;
            postfix_list = add_node(postfix_list, 2, &data);
            flag = 1;
        }
        if (compare_helper(list) == 3) push_sym(&stack, "(");
        if (compare_helper(list) == 5) push_sym(&stack, "~");
        if (compare_helper(list) == 4) {
            while ((strcmp(stack->value, "#") != 0) && (strcmp(stack->value, "(") != 0)) {
                char *sar = pop_sym(&stack);
                size_t min_len = strlen(sar);
                for (size_t k = 0; k < min_len; k++) {
                    data.cmnd[k] = sar[k];
                }
                for (size_t k = min_len; k < 5; k++) {
                    data.cmnd[k] = ' ';
                }
                postfix_list = add_node(postfix_list, 3, &data);
                flag = 1;
            }
            pop_sym(&stack);
        }
        if (compare_helper(list) == 0) {
            if (priority_compare(stack, list)) push_sym(&stack, list->data.cmnd);
            else
                parser_helper(stack, list, postfix_list, &flag);
        }
        list = list->next;
        if (flag == 1 && flag1 == 1) {
            result = postfix_list;
            flag1 = 0;
        }
    }
    stack_to_list(stack, postfix_list);
    return result;
}

void parser_helper(stack_sym *stack, struct node *list, struct node *postfix_list, int *flag) {
    union Data data;
    while ((strcmp(stack->value, "#") != 0) && (priority_compare(stack, list) == 0)) {
        char *sar = pop_sym(&stack);
        size_t min_len = strlen(sar);
        for (size_t k = 0; k < min_len; k++) {
            data.cmnd[k] = sar[k];
        }
        for (size_t k = min_len; k < 5; k++) {
            data.cmnd[k] = ' ';
        }
        postfix_list = add_node(postfix_list, 3, &data);
        *flag = 1;
    }
    push_sym(&stack, list->data.cmnd);
}

int compare_helper(struct node *list) {
    int flag = 0;
    if (list->type == 1) {
        flag = 1;
    }
    if (list->type == 2) {
        flag = 2;
    }
    if (list->type == 3) {
        if (strcmp(list->data.cmnd, "(") == 0) {
            flag = 3;
        } else if (strcmp(list->data.cmnd, ")") == 0) {
            flag = 4;
        } else if (strcmp(list->data.cmnd, "~") == 0) {
            flag = 5;
        }
    }
    return flag;
}

int priority_compare(stack_sym *stack, struct node *list) {
    int flag = 1;
    if (priority_number(list->data.cmnd) <= priority_number(stack->value)) {
        flag = 0;
    }
    return flag;
}

int priority_number(char *ch) {
    int flag = 0;
    if (strcmp(ch, "+") == 0 || strcmp(ch, "-") == 0) {
        flag = 1;
    } else if (strcmp(ch, "*") == 0 || strcmp(ch, "/") == 0) {
        flag = 2;
    } else if (strcmp(ch, "~") == 0 || strcmp(ch, "sin") == 0 ||
    strcmp(ch, "cos") == 0 || strcmp(ch, "tan") == 0
    || strcmp(ch, "ctg") == 0 || strcmp(ch, "ln") == 0 || strcmp(ch, "sqrt") == 0) {
        flag = 3;
    }
    return flag;
}

void stack_to_list(stack_sym *stack, struct node *result) {
    while (strcmp(stack->value, "#") != 0) {
        union Data data;
        char *sar = pop_sym(&stack);
        size_t min_len = strlen(sar);
        for (size_t k = 0; k < min_len; k++) {
            data.cmnd[k] = sar[k];
        }
        for (size_t k = min_len; k < 5; k++) {
            data.cmnd[k] = ' ';
        }
        result = add_node(result, 3, &data);
    }
    destroy_sym(&stack);
}
