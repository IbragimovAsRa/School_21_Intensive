#ifndef SRC_DRAW_H_
#define SRC_DRAW_H_

#define PI 3.14159265358979
#define SIZE_X 80
#define SIZE_Y 25

#include <stdio.h>
#include <math.h>

void draw_helper(const double  *y, double y_start, double y_step, int i, int j);
void draw(double *y);

#endif  // SRC_DRAW_H_
