#include "s21_math.h"

long double s21_atan(double x) {
  long double last_elem;
  long double res_of_sum = 0;
  int counter = 0;
  int check_border = 0;

  // граничные условия
  if (x != x) {
    res_of_sum = x;
  } else if (x == -S21_INF || x == S21_INF) {
    res_of_sum = x < 0 ? -(S21_PI / 2) : (S21_PI / 2);
  } else if (x == 1) {
    res_of_sum = 0.7853981633974483L;
  } else if (x == -1) {
    res_of_sum = -0.7853981633974483L;
  } else {
    check_border = 1;
  }

  if (check_border && s21_fabs(x) < 1) {
    do {
      if (counter % 2 == 0) {
        last_elem = s21_pow(x, 1 + 2 * counter) / (1 + 2 * counter);
        res_of_sum += last_elem;
      } else {
        last_elem = s21_pow(x, 1 + 2 * counter) / (1 + 2 * counter);
        res_of_sum += -1 * last_elem;
      }
      counter += 1;
    } while (counter < 5000);
  } else if (check_border && s21_fabs(x) > 1) {
    res_of_sum = S21_PI * s21_sqrt(s21_pow(x, 2)) / (2 * x);
    do {
      last_elem = s21_pow(x, -1 - 2 * counter) / (1 + 2 * counter);
      if (counter % 2 == 0) {
        res_of_sum -= last_elem;
      } else {
        res_of_sum += last_elem;
      }
      counter += 1;
    } while (counter < 5000);
  }

  return res_of_sum;
}
