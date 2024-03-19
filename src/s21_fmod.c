#include "s21_math.h"

#define S21_EPS 1e-7

long double s21_fmod(double x, double y) {
  long double res = 0;

  if (x != x || y != y || x == S21_INF || x == -S21_INF ||
      s21_fabs(y) < S21_EPS) {
    res = S21_NAN;
  } else if (y == S21_INF || y == -S21_INF) {
    res = x;
  } else {
    if (y < 0) {
      y *= -1;
    }
    if (x < 0) {
      x *= -1;
      res = -1 * (x - y * (s21_floor(x / y)));
    } else {
      res = x - y * (s21_floor(x / y));
    }
  }

  return res;
}
