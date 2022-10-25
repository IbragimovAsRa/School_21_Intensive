#ifndef SRC_STACK_H_
#define SRC_STACK_H_

typedef struct stack_sym {
    char *value;
    struct stack_sym *next;
} stack_sym;

stack_sym *init_sym(char *value);
void push_sym(stack_sym **head, char *value);
char* pop_sym(stack_sym **head);
void destroy_sym(stack_sym **head);

typedef struct stack_num {
    double value;
    struct stack_num *next;
} stack_num;

stack_num *init_num(double value);
void push_num(stack_num **head, double value);
double pop_num(stack_num **head);
void destroy_num(stack_num **head);
int getSize(stack_num **head);

#endif  // SRC_STACK_H_

