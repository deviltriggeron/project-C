#include "test_me.h"

START_TEST(test_div_1) {
  decimal src1, src2, result, origin;
  // 30064771176
  // 3
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01010101010101010101010101111000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_div_2) {
  decimal src1, src2, result;
  int a = 32768;
  int b = -2;
  int res_our_dec = 0;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  int res_origin = -16384;
  int check = div(src1, src2, &result);
  int check_origin = 0;
  from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(test_div_3) {
  decimal src1, src2, result;
  int a = 32768;
  int b = 2;
  int res_our_dec = 0;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  int res_origin = 16384;
  int check = div(src1, src2, &result);
  int check_origin = 0;
  from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(test_div_4) {
  decimal src1, src2, result, origin;
  // -30064771176
  // 2
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b10000000000000000000000000110100;
  origin.bits[1] = 0b00000000000000000000000000000011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_div_5) {
  decimal src1, src2, result, origin;
  // 0
  // 0.015
  // 0
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_div_6) {
  decimal src1, src2 = {0}, result, origin;
  from_int_to_decimal(-101, &src1);
  src2.bits[0] = 0b00000000000000000000000001100101;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int check = div(src1, src2, &result);
  int check_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_div_7) {
  // decimal src1, src2, result;
  // float a = 1.0 / 0.0;
  // float b = 1.0 / 0.0;
  // from_float_to_decimal(a, &src1);
  // from_float_to_decimal(b, &src2);
  // int check = div(src1, src2, &result);
  // int check_origin = 3;
  // ck_assert_int_eq(check, check_origin);
  // ck_assert_int_eq(result.bits[3], 0);
  // ck_assert_int_eq(result.bits[2], 0);
  // ck_assert_int_eq(result.bits[1], 0);
  // ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_div_8) {
  // decimal src1, src2, result;
  // float a = -115.2;
  // float b = 0.0;
  // from_float_to_decimal(a, &src1);
  // from_float_to_decimal(b, &src2);
  // int check = div(src1, src2, &result);
  // int check_origin = 3;
  // ck_assert_int_eq(check_origin, check);
  // ck_assert_int_eq(result.bits[3], 0);
  // ck_assert_int_eq(result.bits[2], 0);
  // ck_assert_int_eq(result.bits[1], 0);
  // ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_div_9) {
  decimal src1, src2, result;
  src1.bits[0] = 0x0006BFD0;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000028;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;

  int check = div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check_origin, check);
  ck_assert_int_eq(result.bits[3], 0x00000000);
  ck_assert_int_eq(result.bits[2], 0x00000000);
  ck_assert_int_eq(result.bits[1], 0x00000000);
  ck_assert_int_eq(result.bits[0], 0x00002B32);
}
END_TEST

START_TEST(test_div_10) {
  // decimal src1, src2, result;
  // src1.bits[0] = 0xDB8FCE66;
  // src1.bits[1] = 0x00000405;
  // src1.bits[2] = 0x00000000;
  // src1.bits[3] = 0x00070000;

  // src2.bits[0] = 0x00009C5C;
  // src2.bits[1] = 0x00000000;
  // src2.bits[2] = 0x00000000;
  // src2.bits[3] = 0x00030000;

  // int check = div(src1, src2, &result);
  // int check_origin = 0;
  // ck_assert_int_eq(check_origin, check);
  // ck_assert_int_eq(result.bits[3], 0x00180000);
  // ck_assert_int_eq(result.bits[2], 0b00100011101101001001001100111010);
  // ck_assert_int_eq(result.bits[1], 0b10110001011111101011000101100100);
  // ck_assert_int_eq(result.bits[0], 0b10100000000111101101101010111010);
  // ck_assert_int_eq(result.bits[3], 0x00180000);
  // ck_assert_int_eq(result.bits[2], 0x23B4933A);
  // ck_assert_int_eq(result.bits[1], -1317097116);
  // ck_assert_int_eq(result.bits[0], -1608590662);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\033[45m-=div=-\033[0m");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_2);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_4);
  tcase_add_test(tc, test_div_5);
  tcase_add_test(tc, test_div_6);
  tcase_add_test(tc, test_div_7);
  tcase_add_test(tc, test_div_8);
  tcase_add_test(tc, test_div_9);
  tcase_add_test(tc, test_div_10);

  suite_add_tcase(s, tc);
  return s;
}