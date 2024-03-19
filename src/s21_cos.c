#include "s21_math.h"

long double s21_cos(double x) {
  // init
  long double last_elem = 0;
  long double res_of_sum = 0;
  int counter = 0;
  int sign = 1;

  if (x == S21_INF || x != x || x == -S21_INF) {
    res_of_sum = S21_NAN;
  } else if (x == 0) {
    res_of_sum = 1;
  } else {
    long double new_x = s21_fmod(s21_fabs(x), 2 * S21_PI);

    if (new_x > S21_PI / 2 && new_x <= S21_PI) {
      sign = -1;
      new_x = new_x - S21_PI / 2;
    } else if (new_x > S21_PI && new_x < 3 * S21_PI / 2) {
      sign = -1;
    }

    // quarter logic
    if (sign == -1) {
      if (new_x <= S21_PI / 2) {
        new_x = S21_PI / 2 - new_x;
      } else if (new_x > S21_PI) {
        new_x = new_x - S21_PI;
      }
    } else if (new_x >= 3 * S21_PI / 2) {
      new_x = S21_PI / 2 - (new_x - 3 * S21_PI / 2);
    }

    // search value in quater
    do {
      last_elem = s21_pow(new_x, 2 * counter) / s21_factorial(2 * counter);
      if (counter % 2 == 0) {
        res_of_sum += last_elem;
      } else {
        res_of_sum -= last_elem;
      }
      counter += 1;
    } while (last_elem > 0.000001);
  }

  return sign * res_of_sum;
}

int s21_factorial(int x) {
  int ret_val = 1;

  if (x > 0) {
    for (int i = 0; i < x; i++) {
      ret_val *= i + 1;
    }
  } else {
    ret_val = 1;
  }

  return ret_val;
}
