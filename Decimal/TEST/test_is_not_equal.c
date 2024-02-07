#include "test_me.h"

START_TEST(test_is_not_equal1) {
  decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(is_not_equal(first, second), 0);
}
END_TEST

START_TEST(test_is_not_equal2) {
  decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(is_not_equal(first, second), 0);
}
END_TEST

START_TEST(test_is_not_equal3) {
  decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 0);
}
END_TEST

START_TEST(test_is_not_equal4) {
  decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 1);
}
END_TEST

START_TEST(test_is_not_equal5) {
  decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 1);
}
END_TEST

START_TEST(test_is_not_equal6) {
  decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 1);
}
END_TEST

START_TEST(test_is_not_equal7) {
  decimal first = {{0, 0, 0, 0b11110100000000000010000111111110}};
  decimal second = {{0, 0, 0, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 0);
}
END_TEST

START_TEST(test_is_not_equal8) {
  decimal first = {
      {1564, 31452, 6109410, 0b11110100000000000010000111111110}};
  decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 1);
}
END_TEST

START_TEST(test_is_not_equal9) {
  decimal first = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  decimal second = {
      {1564, 3142, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 1);
}
END_TEST

START_TEST(test_is_not_equal10) {
  decimal first = {
      {15614, 31452, 610941, 0b11110100000000000010000111111110}};
  decimal second = {
      {1564, 31452, 610941, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_not_equal(first, second), 1);
}
END_TEST

START_TEST(test_is_not_equal11) {
  decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_not_equal12) {
  decimal src1, src2;
  int origin;
  // src1 = 2.22221200000000000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010000000000000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = is_not_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_not_equal13) {
  decimal src1, src2;
  int origin;
  // src1 = 3.2222121;
  // src2 = 3.222212;
  src1.bits[0] = 0b00000001111010111010101110101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  src2.bits[0] = 0b00000000001100010010101011000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_not_equal14) {
  decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.222212;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_is_not_equal15) {
  decimal src1, src2;
  int origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create("\033[45m-=is_not_equal=-\033[0m");
  TCase *tc = tcase_create("is_not_equal_tc");

  tcase_add_test(tc, test_is_not_equal1);
  tcase_add_test(tc, test_is_not_equal2);
  tcase_add_test(tc, test_is_not_equal3);
  tcase_add_test(tc, test_is_not_equal4);
  tcase_add_test(tc, test_is_not_equal5);
  tcase_add_test(tc, test_is_not_equal6);
  tcase_add_test(tc, test_is_not_equal7);
  tcase_add_test(tc, test_is_not_equal8);
  tcase_add_test(tc, test_is_not_equal9);
  tcase_add_test(tc, test_is_not_equal10);
  tcase_add_test(tc, test_is_not_equal11);
  tcase_add_test(tc, test_is_not_equal12);
  tcase_add_test(tc, test_is_not_equal13);
  tcase_add_test(tc, test_is_not_equal14);
  tcase_add_test(tc, test_is_not_equal15);

  suite_add_tcase(s, tc);
  return s;
}