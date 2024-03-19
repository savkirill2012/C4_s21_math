#include "s21_math.h"

/*
  e^x аппроксимируется рядом Тейлора
  sum = 1 + x + x^2/2! + x^3/3! + x^4/4! + x^5/5! + ...
*/

long double s21_exp(double x) {
  long double x_cast = (long double)x;
  long double step = 1;
  long double sum = 1;
  int is_negative = 1;
  unsigned int i = 1;

  x_cast < 0 ? x_cast *= -1 : (is_negative = 0);

  for (; sum + step != sum && step < __LDBL_MAX__; i++) {
    step *= x_cast / i;
    sum += step;
  }

  if (is_negative == 1) {
    if (sum > __LDBL_MAX__) {
      sum = 0;
    } else {
      sum = 1 / sum;
    }
  } else if (sum > __LDBL_MAX__) {
    sum = __builtin_inff();
  }

  return sum;
}
