#include "data_stat.h"

double max(double *data, int n) {
  double max = data[0];
  for (int i = 0; i < n; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  return max;
}
double min(double *data, int n) {
  double min = data[0];
  for (int i = 0; i < n; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}
double mean(double *data, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += data[i];
  }
  return sum / (1.0 * n);
}
double variance(double *data, int n) {
  double mn;
  mn = mean(data, n);
  double sum_sq = 0;

  for (int i = 0; i < n; i++) {
    sum_sq += (mn - data[i]) * (mn - data[i]);
  }

  return sum_sq / (n * 1.0);
}
