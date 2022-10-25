#ifndef SRC_CALCULATIONS_H_
#define SRC_CALCULATIONS_H_

double calculate_polish_notation(struct node *list, int length, double number);
double calculator_helper(struct node *list, stack_num *stack);
int check_operation(char comm);

#endif  // SRC_CALCULATIONS_H_
