#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#define DIGITS '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
#define N_DIGITS 10

#define SYMBOLS '-', '+', '*', '/'
#define N_SYMBOLS 4

#define COMMANDS "cos", "sin", "tan", "ctg", "sqrt", "ln"
#define N_COMMANDS 6

#define CMND_LETTERS 'c', 'o', 's', 'i', 'n', 't', 'a', 'g', 's', 'q', 'r', 'l'
#define N_LETTERS 12

#define MAX_LEN 308  // the maximum length of a double
#define MAX_INPUT_LEN 1000

#include <stdlib.h>
#include <string.h>

#include "list.h"

int input(struct node* root);

void get_input(char str[MAX_INPUT_LEN], int* len);
void add_spaces(const char str1[MAX_INPUT_LEN], char str2[MAX_INPUT_LEN], int* len);

int digit_detect(char ch);
int symb_detect(char ch);
int cmnd_letter_detect(char ch);
int char_type_detection(char ch);

int num_valid(char token[MAX_LEN], int len);
int command_valid(char token[MAX_LEN]);
int string_type_validation(char token[MAX_LEN], int type, int len);

double get_num(char token[MAX_LEN]);
union Data get_data(char token[MAX_LEN], int type);

int neighbours_validation(struct node* root, int count);
int parenthese_validation(struct node* root);
int border_validation(struct node* root, int count);

void type_redefinition(struct node* root);

#endif  // SRC_INPUT_H_
