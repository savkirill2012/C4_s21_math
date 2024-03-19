#include "s21_math.h"

long double s21_asin(double x) {
  long double ret_val;

  if (x < 1 && x > -1) {
    // double new_x = x/sqrt(1 - pow(x, 2));
    // ret_val = s21_atan(new_x);
    ret_val = (S21_PI / 2) - s21_acos(x);
  } else if (x == 1 || x == -1) {
    ret_val = (S21_PI / 2) * x;
  } else {
    ret_val = S21_NAN;
  }

  return ret_val;
}
