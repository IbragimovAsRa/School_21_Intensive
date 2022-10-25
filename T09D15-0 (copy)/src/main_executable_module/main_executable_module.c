#ifndef Dynamic
#include "../data_module/data_process.h"
#endif
#ifdef Dynamic
#include "../../build/data_process.so"
#endif
#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../yet_another_decision_module/decision.h"
#include "data_sort.h"

int main() {
  int n;
  scanf("%d", &n);
  double *data = malloc(n * sizeof(double));

  printf("LOAD DATA...\n");
  input(data, n);

  printf("RAW DATA:\n\t");
  output(data, n);

  printf("\nNORMALIZED DATA:\n\t");
  if (normalization(data, n)) {
    output(data, n);
  } else {
    printf("ERROR");
  }

  printf("\nSORTED NORMALIZED DATA:\n\t");
  sort(data, n);
  output(data, n);

  printf("\nFINAL DECISION:\n\t");
  if (make_decision(data, n))
    printf("YES");
  else
    printf("NO");
  free(data);
  return 0;
}
