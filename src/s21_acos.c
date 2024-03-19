#include "s21_math.h"

long double s21_acos(double x) {
  double new_x = s21_sqrt(1 - x * x) / x;
  long double ret_val = S21_NAN;

  if (x >= 0 && x < 1) ret_val = s21_atan(new_x);
  if ((x < 0 && x > -1)) ret_val = S21_PI + s21_atan(new_x);
  if (x == 1) ret_val = 0;
  if (x == -1) ret_val = S21_PI;

  return ret_val;
}
