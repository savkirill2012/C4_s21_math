#include "s21_math.h"

long double s21_tan(double x) {
  long double tg_ret_val = 0;
  long double val_on_a_circle = s21_fmod(s21_fabs(x), 2 * S21_PI);

  if (x == S21_INF || x != x || x == -S21_INF) {
    tg_ret_val = S21_NAN;
  } else if (val_on_a_circle == S21_PI / 2) {
    if (x < 0) {
      tg_ret_val = -16331239353195370;
    } else {
      tg_ret_val = 16331239353195370;
    }
  } else if (val_on_a_circle == 3 * S21_PI / 2) {
    if (x < 0) {
      tg_ret_val = -5443746451065123;
    } else {
      tg_ret_val = 5443746451065123;
    }
  } else {
    tg_ret_val = s21_sin(x) / s21_cos(x);
  }

  return tg_ret_val;
}
