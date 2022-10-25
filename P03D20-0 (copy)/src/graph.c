#include "polish_notation.h"
#include "list.h"
#include "calculations.h"
#include "draw.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node* root = malloc(sizeof(struct node));
    if (input(root)) {
        int len = count_node(root);
        struct node *result = parse_list(root, len);
        int new_len = count_node(result);
        double *arr = malloc(80 * sizeof(double));
        for (int i = 0; i < 80; i++) {
            double step = 4 * PI * i / 79;
            arr[i] = calculate_polish_notation(result, new_len, step);
        }
        draw(arr);
        free(arr);
        destroy(result);
    } else {
        printf("input error\n");
    }
    if (root != NULL) destroy(root);
    return 0;
}
