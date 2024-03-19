#include "s21_math.h"

long double s21_ceil(double x) {
  long double fraction = x - (long long int)x;
  long double result = 0;

  if (__builtin_isfinite(x) && fraction != 0 && x != __DBL_MAX__) {
    fraction > 0 ? (result = x - fraction + 1) : (result = x - fraction);
  } else {
    result = x;
  }

  return result;
}
