#include "s21_math.h"

// тоже самое с граничными условиями
long double s21_pow(double x, double y) {
  long double res = 0;

  if (x == 1.0 || y == 0.0 || (x == -1 && (y == -S21_INF || y == S21_INF))) {
    res = 1;
  } else if (x == -S21_INF && y > 0.0) {
    res = -S21_INF;
  } else if ((x == 0.0 && y < 0.0) || ((x < -1.0 || x > 1.0) && y == S21_INF) ||
             (x == S21_INF && y > 1.0)) {
    res = S21_INF;
  } else if ((x == 0.0 && y >= 0.0) ||
             ((x < -1.0 || 1.0 < x) && y == -S21_INF) ||
             (x == S21_INF && y < 0.0) || (0 < x && x < 1 && y == S21_INF)) {
    res = 0;
  } else if (x < 0.0 && s21_fmod(y, 1.0)) {
    res = -1 * S21_NAN;
  } else if (x < 0.0 && s21_fmod(y, 2.0)) {
    res = -1 * s21_exp(y * s21_log(s21_fabs(x)));
  } else {
    res = s21_exp(y * s21_log(s21_fabs(x)));
  }

  return res;
}

// long double s21_pow(double x, double y) {
//     double res = 1;
//     if(y == 0) {
//         res = 1;
//     } else if(y == 1) {
//         res = x;
//     } else {
//         int abs = x < 0 ? -1 : 1;
//         res = s21_exp(y * s21_log(x*abs));
//         if (s21_fmod(y, 2)) {
//             res *= abs;
//         }
//     }
//     return res;
// }

// long double s21_pow(double x, double y) {
//   if (!y) return 1;
//   if (x == S21_INF_NEG && y == S21_INF_NEG) return 0;
//   if (x == S21_INF_NEG && y == S21_INF_POS) return S21_INF_POS;
//   if (x < 0 && y != (long long int)y) return S21_NAN;
//   long double res = 0;
//   int sign = x < 0 ? -1 : 1;
//   res = s21_exp(y * s21_log(x * sign));
//   if (s21_fmod(y, 2)) res *= sign;
//   return res;
// }
