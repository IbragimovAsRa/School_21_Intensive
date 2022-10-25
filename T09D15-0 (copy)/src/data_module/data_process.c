

#include "data_process.h"
#include "../data_libs/data_stat.h"
#include <math.h>

int normalization(double *data, int n) {
  int result = 1;
  double max_value = max(data, n);
  double min_value = min(data, n);
  double size = max_value - min_value;

  if (fabs(size) > 1E-6) {
    for (int i = 0; i < n; i++) {
      data[i] = 1.0 * data[i] / size * 1.0 - min_value * 1.0 / size * 1.0;
    }
  } else {
    result = 0;
  }

  return result;
}
