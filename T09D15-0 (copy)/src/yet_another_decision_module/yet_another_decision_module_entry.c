#include "../data_libs/data_io.h"
#include "decision.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  double *data = malloc(n * sizeof(double));
  input(data, n);
  if (make_decision(data, n)) {
    printf("YES");
  } else {
    printf("NO");
  }
  free(data);
  return 0;
}
