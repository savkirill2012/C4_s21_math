#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_EXP 2.7182818284590451

// sharikaj
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);

// carddeme
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);

// itchyole
int s21_abs(int x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_floor(double x);

// tammirav
long double s21_exp(double x);

// help function
int s21_factorial(int x);

#endif  // SRC_S21_MATH_H_
