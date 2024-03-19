#include "s21_math.h"

long double s21_fabs(double x) {
  return __builtin_isinf(x) ? __builtin_inff()
         : x < 0            ? (long double)-x
                            : (long double)x;
}
