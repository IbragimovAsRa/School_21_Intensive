#include "draw.h"

void draw(double *y) {
    double y_step = (1.0 * 2) / 24;
    double y_start = -1;
    for (int i = 0; i < SIZE_Y; i++) {
        for (int j = 0; j < SIZE_X; j++) {
            if (j == SIZE_X - 1) {
                draw_helper(y, y_start, y_step, i, j);
                printf("\n");
            } else {
                draw_helper(y, y_start, y_step, i, j);
            }
        }
    }
}

void draw_helper(const double  *y, double y_start, double y_step, int i, int j) {
    if ((y[j] >= (y_start + y_step * i) - y_step / 2) &&
        (y[j] < (y_start + y_step * i) + y_step / 2)) {
        printf("*");
    } else {
        printf(".");
    }
}
