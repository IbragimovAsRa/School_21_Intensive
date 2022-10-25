#ifndef SRC_POLISH_NOTATION_H_
#define SRC_POLISH_NOTATION_H_
#include "stack.h"

int priority_number(char *ch);
struct node *parse_list(struct node *list, int length);
int priority_compare(stack_sym *stack, struct node *list);
void stack_to_list(stack_sym *stack, struct node *result);
int compare_helper(struct node *list);
void parser_helper(stack_sym *stack, struct node *list, struct node *postfix_list, int *flag);

#endif  // SRC_POLISH_NOTATION_H_
