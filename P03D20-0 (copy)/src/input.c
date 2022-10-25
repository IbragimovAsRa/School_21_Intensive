#include "input.h"

// the main function

int input(struct node* root) {
    // 1 input token = 1 element of the list

    char raw_str[MAX_INPUT_LEN];
    int str_len = 0;

    get_input(raw_str, &str_len);

    char str[MAX_INPUT_LEN];
    add_spaces(raw_str, str, &str_len);

    struct node* cur = root;
    int tok_count = 0, error = 0, char_count = 0;;

    // get all tokens loop
    while (root != NULL && !error && char_count < str_len) {
        char token[MAX_LEN] = "";
        int len = 0, type = 0;
        char ch = str[char_count];  // to initialize the loop

        // get one token loop
        // check if input chars are appropriate
        while (ch != ' ' && ch != '\n' && ch != '\0' && !error) {
            token[len] = ch;

            // wrong input >> error
            if (!type) {
                type = char_type_detection(ch);
                if (!type) {
                    error = 1;
                }
            }

            // symbols have len = 1 only
            if (type == 2 && len > 1) error = 1;

            // commands have max len = 4
            if (type == 3 && len > 4) error = 1;

            len++;
            char_count++;

            ch = str[char_count];
        }

        char_count++;

        // check if the whole string is appropriate. applied only to nums and cmnds
        int valid = string_type_validation(token, type, len);

        // write the token to the list
        if (valid) {
            cur->type = type;
            cur->data = get_data(token, type);
            cur->next = malloc(sizeof(struct node));
            cur = cur->next;
            tok_count++;
        }

        // check if two neighbour tokens are compatible
        if (!neighbours_validation(root, tok_count)) error = 1;
    }

    // non-valid parenthese and border tokens or other errors >> return NULL
    if ((!parenthese_validation(root) || !border_validation(root, tok_count) || error) && root != NULL) {
        error = 1;
    }

    if (root != NULL) type_redefinition(root);

    return !error;
}

void get_input(char str[MAX_INPUT_LEN], int* len) {
    char ch = 'x';  // to start
    while (ch != '\n' && ch != '\0') {
        ch = getchar();
        str[*len] = ch;
        (*len)++;
    }
}

void add_spaces(const char str1[MAX_INPUT_LEN], char str2[MAX_INPUT_LEN], int* len) {
    int count = 0;
    for (int i = 0; i < *len; i++) {
        if (str1[i] != ')' && str1[i] != '(' && str1[i] != '-') {
            str2[count] = str1[i];
            count++;
        } else {
            if (str1[i] != '-') {  // spaces on two sides of parentheses
                str2[count] = ' ';
                count++;
                str2[count] = str1[i];
                count++;
                str2[count] = ' ';
                count++;
            } else {  // space after '-'
                str2[count] = str1[i];
                count++;
                str2[count] = ' ';
                count++;
            }
        }
    }
    *len = count;
}

// char detection

int digit_detect(char ch) {
    int detect = 0;
    const char digits[N_DIGITS] = {DIGITS};
    for (int i = 0; i < N_DIGITS && !detect; i++) {
        if (ch == digits[i]) detect = 1;
    }
    if (ch == '.' || ch == '-') detect = 1;
    return detect;
}

int symb_detect(char ch) {
    int detect = 0;
    const char symbols[N_SYMBOLS] = {SYMBOLS};
    for (int i = 0; i < N_SYMBOLS && !detect; i++) {
        if (ch == symbols[i]) detect = 1;
    }
    if (ch == '(' || ch == ')') detect = 2;
    if (ch == 'x') detect = 3;
    return detect;
}

int cmnd_letter_detect(char ch) {
    int detect = 0;
    const char letters[N_LETTERS] = {CMND_LETTERS};
    for (int i = 0; i < N_LETTERS && !detect; i++) {
        if (ch == letters[i]) detect = 1;
    }
    return detect;
}

int char_type_detection(char ch) {
    int type = 0;

    // NEED TO DIFFER "-1" FROM "-", "1" !!!

    if (digit_detect(ch)) type = 1;  // num
    if (symb_detect(ch) == 1) type = 2;  // symbol
    if (cmnd_letter_detect(ch)) type = 3;  // command
    if (symb_detect(ch) == 2) type = 4;  // parenthese
    if (symb_detect(ch) == 3) type = 5;  // var

    return type;
}

// string validation

int num_valid(char token[MAX_LEN], int len) {
    int valid = 1;

    // minus not as the first char
    if (strchr(token + 1, '-') != NULL) valid = 0;

    // starts with zero
    if (token[0] == '0' && len > 1) valid = 0;

    // dot in the beginning or end of the string
    if (token[0] == '.' || token[len - 1] == '.') valid = 0;

    // more than 1 dot
    char* temp = strchr(token, '.');
    if (temp != NULL && strchr(temp + 1, '.') != NULL) valid = 0;

    return valid;
}

int command_valid(char token[MAX_LEN]) {
    int valid = 0;
    char commands[N_COMMANDS][MAX_LEN] = {COMMANDS};
    for (int i = 0; i < N_COMMANDS && !valid; i++) {
        if (strcmp(token, commands[i]) == 0) valid = 1;
    }
    return valid;
}

int string_type_validation(char token[MAX_LEN], int type, int len) {
    int valid = 0;

    if (type == 2 || type == 4 || type == 5) valid = 1;  // symbol, parenthese, variable
    if (type == 1) valid = num_valid(token, len);  // nums
    if (type == 3) valid = command_valid(token);  // commands

    return valid;
}

// extraction of the data from the string

double get_num(char token[MAX_LEN]) {
    double num;
    num = strtod(token, &token);  // i don't know why it works (in online compiler) but it works
    return num;
}

union Data get_data(char token[MAX_LEN], int type) {
    union Data data;

    if (type == 3) strcpy(data.cmnd, token);  // command
    if (type == 2 || type == 4 || type == 5) data.symb = token[0];  // symbol, parenthese, variable
    if (type == 1) data.num = get_num(token);  // num

    return data;
}

// neighbours validation

int neighbours_validation(struct node* root, int count) {
    int valid = 1;

    if (count > 1) {  // if we've got at least two tokens
        int iter = 0;
        while (iter < count - 2) {
            root = root->next;
            iter++;
        }
        // now root = previous token, root->next = current token
        if (root->type != 4 && root->type == root->next->type) valid = 0;  // "2 2", "- *", "sqrt sin", "x x"
        if (root->type == 3 && root->next->type != 4) valid = 0;  // "sqrt +", "sqrt 2", "sqrt x"
        if (root->type == 5 && root->next->type != 4 && root->next->type != 2) valid = 0;  // "x 2", "x sqrt"
    }

    return valid;
}

int parenthese_validation(struct node* root) {
    int open = 0, valid = 1;
    while (root != NULL && valid) {
        if (root->type == 4) {
            if ((root->data.symb) == '(') open++;
            if ((root->data.symb) == ')') {
                if (open > 0) {
                    open--;
                } else {
                    valid = 0;
                }
            }
        }
        root = root->next;
    }

    return valid;
}

int border_validation(struct node* root, int count) {
    int valid = 1;

    // first != symbol
    if (root->type == 2) valid = 0;

    // find the last token
    while (root->next->type != 0) {
        root = root->next;
    }

    // last != symbol
    if (root->type == 2) valid = 0;

    // last != command
    if (root->type == 3) valid = 0;

    // if we have 1 token and it's not "y = x" or "y = 0.5"
    if (count == 1 && root->type != 1 && root->type != 5) valid = 0;

    return valid;
}

// special for Artem
// now type 1 = num, type 2 = variable x, type 3 = commands (including "+", ")", "sin"...)
void type_redefinition(struct node* root) {
    while (root != NULL && root->type != 0) {
        if (root->type == 2 || root->type == 4) {
            root->type = 3;
            char temp[5] = "\0";
            temp[0] = root->data.symb;
            strcpy(root->data.cmnd, temp);
        }
        if (root->type == 5) root->type = 2;

        root = root->next;
    }
}
