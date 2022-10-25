
#include <stdio.h>
#include <stdlib.h>

void output(int **a, int y, int x);
int input(int **a, int y, int x);

int main() {
  int row_size;
  int column_size;
  int regime;
  char ch;
  int array[100][100];
  int flag = 0;
  if ((scanf("%d%c", &regime, &ch) != 0 &&
       (regime == 1 || regime == 2 || regime == 3 || regime == 4) &&
       ch == '\n')) {
    switch (regime) {
    case 1:
      if (scanf("%d%d%c", &row_size, &column_size, &ch) == 3 && ch == '\n') {
        for (int i = 0; i < row_size; i++) {
          for (int j = 0; j < column_size; j++) {
            if (scanf("%d", &array[i][j]) == 0 && flag != 1) {
              printf("n/a");
              flag = 1;
            }
            if (i == row_size - 1 && j == column_size - 1 && flag != 1) {
              if (scanf("%c", &ch) != 0 && ch != '\n') {
                printf("n/a");
                flag = 1;
              }
            }
          }
        }
        for (int i = 0; i < row_size; i++) {
          for (int j = 0; j < column_size; j++) {
            printf("%d", array[i][j]);
            if (j != column_size - 1) {
              printf(" ");
            }
            if (j == column_size - 1 && i != row_size - 1) {
              printf("\n");
            }
          }
        }
      } else {
        printf("n/a");
        flag = 1;
      }
      break;
    case 2:
      if (scanf("%d%d%c", &row_size, &column_size, &ch) == 3 && ch == '\n') {
        int **pointer_array = malloc(row_size * sizeof(int *));
        int *values_array = malloc(row_size * column_size * sizeof(int));
        for (int i = 0; i < row_size; i++) {
          pointer_array[i] = values_array + column_size * i;
        }
        flag = input(pointer_array, row_size, column_size);
        if (flag != 1) {
          output(pointer_array, row_size, column_size);
        }
        free(values_array);
        free(pointer_array);
      } else {
        printf("n/a");
        flag = 1;
      }
      break;
    case 3:
      if (scanf("%d%d%c", &row_size, &column_size, &ch) == 3 && ch == '\n') {
        int **pointer_array2 = malloc(row_size * sizeof(int *));
        for (int i = 0; i < row_size; i++) {
          pointer_array2[i] = malloc(column_size * sizeof(int));
        }
        flag = input(pointer_array2, row_size, column_size);
        if (flag != 1) {
          output(pointer_array2, row_size, column_size);
        }
        for (int i = 0; i < row_size; i++) {
          free(pointer_array2[i]);
        }
        free(pointer_array2);
      } else {
        printf("n/a");
        flag = 1;
      }
      break;
    case 4:
      if (scanf("%d%d%c", &row_size, &column_size, &ch) == 3 && ch == '\n') {
        int **single_array_matrix = malloc(
            row_size * column_size * sizeof(int) + row_size * sizeof(int *));
        int *ptr = (int *)(single_array_matrix + row_size);
        for (int i = 0; i < row_size; i++) {
          single_array_matrix[i] = ptr + column_size * i;
        }
        flag = input(single_array_matrix, row_size, column_size);
        if (flag != 1) {
          output(single_array_matrix, row_size, column_size);
        }
        free(single_array_matrix);
      } else {
        printf("n/a");
        flag = 1;
      }
      break;
    }
  } else {
    printf("n/a");
    flag = 1;
  }
  return flag;
}

void output(int **a, int y, int x) {
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      printf("%d", a[i][j]);

      if (j != x - 1) {
        printf(" ");
      }
      if (j == x - 1 && i != y - 1) {
        printf("\n");
      }
    }
  }
}
int input(int **a, int y, int x) {
  int flag = 0;
  char ch;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (scanf("%d", &a[i][j]) == 0 && flag != 1) {
        printf("n/a");
        flag = 1;
      }
      if (i == y - 1 && j == x - 1 && flag != 1) {
        if (scanf("%c", &ch) != 0 && ch != '\n') {
          printf("n/a");
          flag = 1;
        }
      }
    }
  }
  return flag;
}
