#include <check.h>
#include <math.h>

#include "s21_math.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

#define S21_EPSILON 1e-6

START_TEST(acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(-0.7), acos(-0.7), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_acos(0.0001), acos(0.0001), S21_EPSILON);
  ck_assert_ldouble_nan(s21_acos(-7.1234));
  // ck_assert_ldouble_nan(acos(-7.1234));
  ck_assert_ldouble_nan(s21_acos(7.12345678901234567));
  // ck_assert_ldouble_nan(acos(7.12345678901234567));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
  ck_assert_ldouble_nan(acos(-S21_INF));
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(-0.7), asin(-0.7), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_asin(0.0001), asin(0.0001), S21_EPSILON);
  ck_assert_ldouble_nan(s21_asin(-7.1234));
  // ck_assert_ldouble_nan(asin(-7.1234));
  ck_assert_ldouble_nan(s21_asin(7.12345678901234567));
  // ck_assert_ldouble_nan(asin(7.12345678901234567));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
  ck_assert_ldouble_nan(asin(-S21_INF));
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(0.0001), atan(0.0001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-7.1234), atan(-7.1234), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(7.12345678901234567),
                           atan(7.12345678901234567), S21_EPSILON);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-S21_INF), S21_EPSILON);
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI + 0.2), cos(S21_PI + 0.2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 2), cos(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI / 2), cos(-S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(3 * S21_PI / 2), cos(3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(-3 * S21_PI / 2), cos(-3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(5.1234567890123456), cos(5.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_cos(3.1234567890123456), cos(3.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(cos(S21_INF));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
  ck_assert_ldouble_nan(cos(-S21_INF));

  for (int i = -360; i <= 360; i++) {
    ck_assert_ldouble_eq_tol(s21_cos(i * S21_PI / 180), cos(i * S21_PI / 180),
                             S21_EPSILON);
  }
}
END_TEST

START_TEST(sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 2), sinl(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI / 2), sin(-S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(3 * S21_PI / 2), sin(3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-3 * S21_PI / 2), sin(-3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(5.1234567890123456), sin(5.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(3.1234567890123456), sin(3.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
  ck_assert_ldouble_nan(sin(-S21_INF));
  for (int i = -360; i <= 360; i++) {
    ck_assert_ldouble_eq_tol(s21_sin(i * S21_PI / 180), sin(i * S21_PI / 180),
                             S21_EPSILON);
  }
}
END_TEST

START_TEST(tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 2), tan(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI / 2), tan(-S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(3 * S21_PI / 2), tan(3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(-3 * S21_PI / 2), tan(-3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(5.1234567890123456), tan(5.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_tan(3.1234567890123456), tan(3.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_ldouble_nan(tan(-S21_INF));
}
END_TEST

START_TEST(log_test) {
  // ck_assert_ldouble_eq(s21_log(0), log(0));
  ck_assert_ldouble_eq_tol(s21_log(0.0001), log(0.0001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(3.1234567890123456), log(3.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_log(13.1234553210123456),
                           log(13.1234553210123456), S21_EPSILON);
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_nan(log(S21_NAN));
  ck_assert_ldouble_eq(s21_log(S21_INF), log(S21_INF));
  ck_assert_ldouble_nan(s21_log(-S21_INF));
  ck_assert_ldouble_nan(log(-S21_INF));
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(0.12, 2.2), pow(0.12, 2.2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(15, 2.5), pow(15, 2.5), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(8239751.123456789012345, 0.0001),
                           pow(8239751.123456789012345, 0.0001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0.0001), pow(0, 0.0001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -2), pow(-2, -2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), S21_EPSILON);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(123.123, S21_INF), pow(123.123, S21_INF));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -1), pow(S21_INF, -1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 1), pow(S21_INF, 1));
  ck_assert_ldouble_eq(s21_pow(123.123, -S21_INF), pow(123.123, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-123.123, -S21_INF), pow(-123.123, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-123.123, S21_INF), pow(-123.123, S21_INF));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 1), pow(-S21_INF, 1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 2), pow(S21_INF, 2));
  ck_assert_ldouble_eq(s21_pow(0.123, S21_INF), pow(0.123, S21_INF));

  ck_assert_ldouble_eq(s21_pow(-1, -S21_INF), pow(-1, -S21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(S21_EPSILON, S21_EPSILON),
                           pow(S21_EPSILON, S21_EPSILON), S21_EPSILON);
  ck_assert_ldouble_nan(s21_pow(-0.1, 0.1));
  ck_assert_ldouble_nan(pow(-0.1, 0.1));
  ck_assert_ldouble_eq(s21_pow(0, 0), pow(0, 0));
  ck_assert_ldouble_eq(s21_pow(0, 1), pow(0, 1));
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
  ck_assert_ldouble_nan(pow(0, S21_NAN));
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(3.1234567890123456),
                           sqrt(3.1234567890123456), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(5.1234567890123456),
                           sqrt(5.1234567890123456), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), S21_EPSILON);
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-5));
  // ck_assert_ldouble_nan(sqrt(-5));
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(S21_INF));
}
END_TEST

START_TEST(fmod_test) {
  for (double x = -876543210.987654321, y = -1234.123; x < 876543210;
       x = x + 567896.987654321, y = y + 12.3) {
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), S21_EPSILON);
  }
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  // ck_assert_ldouble_nan(fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_fmod(123.123, S21_INF), fmod(123.123, S21_INF),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(-123.123, S21_INF), fmod(-123.123, S21_INF),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(123.123, -S21_INF), fmod(123.123, -S21_INF),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(-123.123, -S21_INF),
                           fmod(-123.123, -S21_INF), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(S21_EPSILON, S21_EPSILON),
                           fmod(S21_EPSILON, S21_EPSILON), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(-S21_EPSILON, -S21_EPSILON),
                           fmod(-S21_EPSILON, -S21_EPSILON), S21_EPSILON);
}
END_TEST

START_TEST(abs_test) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(-7), abs(-7));
  ck_assert_int_eq(s21_abs(7), abs(7));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(0.000001), fabs(0.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.000001), fabs(-0.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.000001), fabs(-1.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(1.000001), fabs(1.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(1.), fabs(1.), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.), fabs(-1.), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(1234567890.), fabs(1234567890.),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(1234567890.123456), fabs(1234567890.123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-1234567890.123456),
                           fabs(-1234567890.123456), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(1111111111.111111), fabs(1111111111.111111),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-2222222222.222222),
                           fabs(-2222222222.222222), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(-3333333333333.33333333333),
                           fabs(-3333333333333.33333333333), S21_EPSILON);
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
  ck_assert_ldouble_nan(s21_fabs(-NAN));
  ck_assert_ldouble_nan(fabs(-NAN));
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
  ck_assert_ldouble_nan(s21_fabs(-NAN));
  ck_assert_ldouble_nan(fabs(-NAN));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_fabs(1.7976931348623158e+308),
                           fabs(1.7976931348623158e+308), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fabs(2.2250738585072014e-308),
                           fabs(2.2250738585072014e-308), S21_EPSILON);
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.0), ceil(-0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(0.000001), ceil(0.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.000001), ceil(-0.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.000001), ceil(-1.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(1.000001), ceil(1.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(1.), ceil(1.), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.), ceil(-1.), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(1234567890.), ceil(1234567890.),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(1234567890.123456), ceil(1234567890.123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-1234567890.123456),
                           ceil(-1234567890.123456), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(9999999999.999999), ceil(9999999999.999999),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-9999999999.999999),
                           ceil(-9999999999.999999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(-9999999999999.99999999999),
                           ceil(-9999999999999.99999999999), S21_EPSILON);
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
  ck_assert_ldouble_nan(s21_ceil(-NAN));
  ck_assert_ldouble_nan(ceil(-NAN));
  ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_ceil(1.7976931348623158e+308),
                           ceil(1.7976931348623158e+308), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_ceil(2.2250738585072014e-308),
                           ceil(2.2250738585072014e-308), S21_EPSILON);
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_eq_tol(s21_floor(0.0), floor(0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-0.0), floor(-0.0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(0.000001), floor(0.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-0.000001), floor(-0.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-1.000001), floor(-1.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(1.000001), floor(1.000001), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(1.), floor(1.), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-1.), floor(-1.), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(1234567890.), floor(1234567890.),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(1234567890.123456),
                           floor(1234567890.123456), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-1234567890.123456),
                           floor(-1234567890.123456), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(9999999999.999999),
                           floor(9999999999.999999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-9999999999.999999),
                           floor(-9999999999.999999), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(-9999999999999.99999999999),
                           floor(-9999999999999.99999999999), S21_EPSILON);
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_nan(s21_floor(-NAN));
  ck_assert_ldouble_nan(floor(-NAN));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_nan(s21_floor(-NAN));
  ck_assert_ldouble_nan(floor(-NAN));
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_floor(1.7976931348623158e+308),
                           floor(1.7976931348623158e+308), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_floor(2.2250738585072014e-308),
                           floor(2.2250738585072014e-308), S21_EPSILON);
}
END_TEST

START_TEST(exp_test) {
  ck_assert_double_eq_tol(s21_exp(0), exp(0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(-0), exp(-0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(0.5), exp(0.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(-0.5), exp(-0.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(1), exp(1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(1.5), exp(1.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(-1.5), exp(-1.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(2), exp(2), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(3), exp(3), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(-66), exp(-66), S21_EPSILON);
  ck_assert_double_eq_tol(s21_exp(-100), exp(-100), S21_EPSILON);
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));
  ck_assert_double_infinite(s21_exp(INFINITY));
  ck_assert_double_infinite(exp(INFINITY));
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

int main(void) {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, acos_test);
  tcase_add_test(tcase, asin_test);
  tcase_add_test(tcase, atan_test);
  tcase_add_test(tcase, cos_test);
  tcase_add_test(tcase, sin_test);
  tcase_add_test(tcase, tan_test);
  tcase_add_test(tcase, log_test);
  tcase_add_test(tcase, pow_test);
  tcase_add_test(tcase, sqrt_test);
  tcase_add_test(tcase, fmod_test);
  tcase_add_test(tcase, abs_test);
  tcase_add_test(tcase, fabs_test);
  tcase_add_test(tcase, ceil_test);
  tcase_add_test(tcase, floor_test);
  tcase_add_test(tcase, exp_test);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
