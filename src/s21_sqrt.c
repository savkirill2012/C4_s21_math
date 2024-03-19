#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = (x == 0) ? 0 : (x == S21_INF) ? S21_INF : S21_NAN;
  if (res != S21_INF) {
    if (x > 0) {
      long double x0 = 1.0;
      for (int i = 0; i < 100; i++) {
        res = x0 - ((x0 * x0 - x) / (2 * x0));
        if (s21_fabs(res - x0) <= 1e-14) {
          break;
        }
        x0 = res;
      }
    }
  }
  return res;
}
