#include "test_me.h"

START_TEST(test_is_less_1) {
  decimal first = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  decimal second = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(is_less(first, second), 1);
}
END_TEST

START_TEST(test_is_less_2) {
  decimal first = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  decimal second = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(is_less(first, second), 0);
}
END_TEST

START_TEST(test_is_less_3) {
  decimal first = {{0, 0, 0, 0b00000000000000000000000000000000}};
  decimal second = {{0, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(is_less(first, second), 0);
}
END_TEST

START_TEST(test_is_less_4) {
  decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(is_less(first, second), 0);
}
END_TEST

START_TEST(test_is_less_5) {
  decimal first = {{0, 0, 0, 0b10000000000000000000000000000000}};
  decimal second = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(is_less(first, second), 0);
}
END_TEST

START_TEST(test_is_less_6) {
  decimal first = {{4412, 5675, 1254, 0b00000011000000000000000000000000}};
  decimal second = {{4412, 5675, 1254, 0b00000101000000000000000000000000}};
  ck_assert_int_eq(is_less(first, second), 0);
}
END_TEST

START_TEST(test_is_less_7) {
  decimal first = {{4422, 5515, 9254, 0b10000000000000110000000000000000}};
  decimal second = {{6312, 5616, 1844, 0b10000000000001010000000000000000}};
  ck_assert_int_eq(is_less(first, second), 1);
}
END_TEST

START_TEST(test_is_less_8) {
  decimal first = {{4412, 5775, 1254, 0b00000000000001110000000000000000}};
  decimal second = {{4412, 5675, 1254, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(is_less(first, second), 0);
}
END_TEST

START_TEST(test_is_less_9) {
  decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_less_10) {
  decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 0;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_less_11) {
  decimal src1, src2;
  int origin;
  // src1 = 12345677.987654345678987654346;
  // src2 = 12345677.987654000000000000000;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b11100111110001110000000000000000;
  src2.bits[1] = 0b11000000010001001001101110001101;
  src2.bits[2] = 0b00100111111001000001101100000000;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_less_12) {
  decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_less_13) {
  decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876531;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110011;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_less_14) {
  decimal src1, src2;
  int origin;
  // src1 = -87654323456.98765456789876530;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b10110010000010100010111100110010;
  src1.bits[1] = 0b10011001010111000101110110000000;
  src1.bits[2] = 0b00011100010100101001100001111111;
  src1.bits[3] = 0b10000000000100010000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_less_15) {
  decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

Suite *test_is_less(void) {
  Suite *s = suite_create("\033[45m-=is_less=-\033[0m");
  TCase *tc = tcase_create("is_less_tc");

  tcase_add_test(tc, test_is_less_1);
  tcase_add_test(tc, test_is_less_2);
  tcase_add_test(tc, test_is_less_3);
  tcase_add_test(tc, test_is_less_4);
  tcase_add_test(tc, test_is_less_5);
  tcase_add_test(tc, test_is_less_6);
  tcase_add_test(tc, test_is_less_7);
  tcase_add_test(tc, test_is_less_8);
  tcase_add_test(tc, test_is_less_9);
  tcase_add_test(tc, test_is_less_10);
  tcase_add_test(tc, test_is_less_11);
  tcase_add_test(tc, test_is_less_12);
  tcase_add_test(tc, test_is_less_13);
  tcase_add_test(tc, test_is_less_14);
  tcase_add_test(tc, test_is_less_15);

  suite_add_tcase(s, tc);
  return s;
}