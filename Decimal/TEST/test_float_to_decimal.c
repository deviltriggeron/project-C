#include "test_me.h"

START_TEST(test_float_to_decimal1) {
  decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-2);

  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal2) {
  decimal val;
  float fl1 = -128.023;
  float fl2 = 12345.37643764;
  float fl1_res = 0;
  float fl2_res = 0;

  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-2);

  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-2);
}
END_TEST
START_TEST(test_float_to_decimal3) {
  decimal val;
  float num = -2.147483609;
  from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147484);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
}
END_TEST

START_TEST(test_float_to_decimal4) {
  decimal val;
  float fl1 = 22.1483603;
  float fl2 = -2.147483609;
  float fl1_res = 0;
  float fl2_res = 0;

  from_float_to_decimal(fl1, &val);
  from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-2);

  from_float_to_decimal(fl2, &val);
  from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal6) {
  // decimal val;
  // from_float_to_decimal(1.02E+09F, &val);
  // ck_assert_int_eq(val.bits[0], 102);
  // ck_assert_int_eq(val.bits[1], 0);
  // ck_assert_int_eq(val.bits[2], 0);
  // ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_float_to_decimal7) {
  decimal val;
  from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_float_to_decimal8) {
  decimal val;
  float a = 1e-30;
  from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_float_to_decimal9) {
  decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  from_float_to_decimal(tmp1, &dec);
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal10) {
  decimal dec;
  from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal11) {
  decimal dec;
  from_float_to_decimal(-2.147483609, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.147483609, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal12) {
  decimal dec;
  from_float_to_decimal(22.1483603, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.1483603, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal13) {
  decimal dec;
  from_float_to_decimal(1.0208, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.0208, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal14) {
  decimal dec;
  from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-2);
}
END_TEST

START_TEST(test_float_to_decimal15) {
  decimal dec;
  float a = 1.0 / 0.0;
  int ret = from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

Suite *test_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=float_to_decimal=-\033[0m");
  TCase *tc = tcase_create("float_to_decimal_tc");

  tcase_add_test(tc, test_float_to_decimal1);
  tcase_add_test(tc, test_float_to_decimal2);
  tcase_add_test(tc, test_float_to_decimal3);
  tcase_add_test(tc, test_float_to_decimal4);
  // tcase_add_test(tc, test_float_to_decimal5);
  tcase_add_test(tc, test_float_to_decimal6);
  tcase_add_test(tc, test_float_to_decimal7);
  tcase_add_test(tc, test_float_to_decimal8);
  tcase_add_test(tc, test_float_to_decimal9);
  tcase_add_test(tc, test_float_to_decimal10);
  tcase_add_test(tc, test_float_to_decimal11);
  tcase_add_test(tc, test_float_to_decimal12);
  tcase_add_test(tc, test_float_to_decimal13);
  tcase_add_test(tc, test_float_to_decimal14);
  tcase_add_test(tc, test_float_to_decimal15);

  suite_add_tcase(s, tc);
  return s;
}