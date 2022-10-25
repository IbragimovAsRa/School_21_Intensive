
#include <stdio.h>
#include <stdlib.h>

void output(int **a, int y, int x);
void max(int **a, int *arr_max, int y, int x);
void min(int **a, int *arr_min, int y, int x);
int input(int **a, int y, int x);

int main() {
  int row_size;
  int column_size;
  int regime;
  char ch;
  int array[100][100];
  int flag = 0;

  int *arr_max = NULL;
  int *arr_min = NULL;

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
        arr_max = (int *)malloc((row_size) * sizeof(int));
        arr_min = (int *)malloc((row_size) * sizeof(int));

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
        printf("\n");

        int max;
        for (int i = 0; i < row_size; i++) {
          max = array[i][0];
          for (int j = 0; j < column_size; j++) {
            if (array[i][j] > max) {
              max = array[i][j];
            }
          }
          arr_max[i] = max;
        }
        for (int i = 0; i < column_size; i++) {
          printf("%d", arr_max[i]);
          if (i != column_size - 1) {
            printf(" ");
          }
        }

        printf("\n");

        int min;
        for (int j = 0; j < column_size; j++) {
          min = array[0][j];
          for (int i = 0; i < row_size; i++) {
            if (array[i][j] < min) {
              min = array[i][j];
            }
          }
          arr_min[j] = min;
        }
        for (int i = 0; i < row_size; i++) {
          printf("%d", arr_min[i]);
          if (i != row_size - 1) {
            printf(" ");
          }
        }
        free(arr_min);
        free(arr_max);
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
        arr_max = (int *)malloc((row_size) * sizeof(int));
        arr_min = (int *)malloc((row_size) * sizeof(int));
        if (flag != 1) {
          output(pointer_array, row_size, column_size);
        }
        printf("\n");
        max(pointer_array, arr_max, row_size, column_size);
        printf("\n");
        min(pointer_array, arr_min, row_size, column_size);
        free(arr_min);
        free(arr_max);
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
        arr_max = (int *)malloc((row_size) * sizeof(int));
        arr_min = (int *)malloc((row_size) * sizeof(int));
        if (flag != 1) {
          output(pointer_array2, row_size, column_size);
        }
        printf("\n");
        max(pointer_array2, arr_max, row_size, column_size);
        printf("\n");
        min(pointer_array2, arr_min, row_size, column_size);
        free(arr_min);
        free(arr_max);
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
        arr_max = (int *)malloc((row_size) * sizeof(int));
        arr_min = (int *)malloc((row_size) * sizeof(int));
        if (flag != 1) {
          output(single_array_matrix, row_size, column_size);
        }
        printf("\n");
        max(single_array_matrix, arr_max, row_size, column_size);
        printf("\n");
        min(single_array_matrix, arr_min, row_size, column_size);
        free(arr_min);
        free(arr_max);
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

void max(int **a, int *arr_max, int y, int x) {
  int max;
  for (int i = 0; i < y; i++) {
    max = a[i][0];
    for (int j = 0; j < x; j++) {
      if (a[i][j] > max) {
        max = a[i][j];
      }
    }
    arr_max[i] = max;
  }

  for (int i = 0; i < y; i++) {
    printf("%d", arr_max[i]);
    if (i != y - 1) {
      printf(" ");
    }
  }
}

void min(int **a, int *arr_min, int y, int x) {
  int min;
  for (int j = 0; j < x; j++) {
    min = a[0][j];
    for (int i = 0; i < y; i++) {
      if (a[i][j] < min) {
        min = a[i][j];
      }
    }
    arr_min[j] = min;
  }
  for (int i = 0; i < y; i++) {
    printf("%d", arr_min[i]);
    if (i != y - 1) {
      printf(" ");
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
