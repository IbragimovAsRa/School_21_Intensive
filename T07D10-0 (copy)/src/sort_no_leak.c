
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int n);
int input(int *p, int n);
void output(int *a, int n);

int main() {
  int size;
  int *n = &size;
  int *p = NULL;
  if (scanf("%d", n) == 0 || *n <= 0) {
    printf("n/a");
    return 1;
  }
  p = (int *)malloc((*n) * sizeof(int));
  if (input(p, size) == 1) {
    printf("n/a");
    return 1;
  }
  quick_sort(p, size);
  output(p, size);
  free(p);
}
int input(int *p, int n) {
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &p[i]) == 0) {
      return 1;
    }
  }
  return 0;
}
void quick_sort(int *a, int n) {
  int i = 0;
  int j = n - 1;
  int mid = a[n / 2];
  do {
    while (a[i] < mid) {
      i++;
    }
    while (a[j] > mid) {
      j--;
    }
    if (i <= j) {
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    }
  } while (i <= j);
  if (j > 0) {
    quick_sort(a, j + 1);
  }
  if (i < n) {
    quick_sort(&a[i], n - i);
  }
}
void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i != n - 1) {
      printf(" ");
    }
  }
}
