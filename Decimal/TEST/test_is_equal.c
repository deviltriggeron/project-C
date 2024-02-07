#include "test_me.h"

START_TEST(test_equal_1) {
  decimal first = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  decimal second = {{4412, 5675, 1254, 0b00000100000000000010000000000000}};
  ck_assert_int_eq(is_equal(first, second), 1);
}
END_TEST

START_TEST(test_equal_2) {
  decimal first = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  decimal second = {{4412, 5675, 1254, 0b10000100000000000010000000000000}};
  ck_assert_int_eq(is_equal(first, second), 1);
}
END_TEST

START_TEST(test_equal_3) {
  decimal first = {{4412, 5675, 1254, 0b10110010000000001110000111000011}};
  decimal second = {{4412, 5675, 1254, 0b11001001000000000010000111111110}};
  ck_assert_int_eq(is_equal(first, second), 1);
}
END_TEST

START_TEST(test_equal_4) {
  decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1254, 0b01110100000000000010000111111110}};
  ck_assert_int_eq(is_equal(first, second), 0);
}
END_TEST

START_TEST(test_equal_5) {
  decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_equal(first, second), 0);
}
END_TEST

START_TEST(test_equal_6) {
  decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_equal(first, second), 0);
}
END_TEST

START_TEST(test_equal_7) {
  decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_equal(first, second), 0);
}
END_TEST

START_TEST(test_equal_8) {
  decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  decimal second = {
      {4412, 5675, 12541, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(is_equal(first, second), 0);
}
END_TEST

START_TEST(test_equal_9) {
  decimal src1, src2;
  int origin;
  // src1 = -79228162514264337593543950335;
  // src2 = -792281625.14264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000101000000000000000000;
  int result = is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_10) {
  decimal src1, src2;
  int origin;
  // src1 = 675432788976.5424354657687;
  // src2 = 67543278.89765424354657687;
  src1.bits[0] = 0b10111110000100011000010110010111;
  src1.bits[1] = 0b11011001001111010001001011000110;
  src1.bits[2] = 0b00000000000001011001011001001000;
  src1.bits[3] = 0b00000000000011010000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_11) {
  decimal src1, src2;
  int origin;
  // src1 = -579895323215489956.67897455465;
  // src2 = -579895323215489956.67897455465;
  src1.bits[0] = 0b11100110001001011001001101101001;
  src1.bits[1] = 0b00111000110110101110001010110100;
  src1.bits[2] = 0b10111011010111111101000100011110;
  src1.bits[3] = 0b10000000000010110000000000000000;
  src2.bits[0] = 0b11100110001001011001001101101001;
  src2.bits[1] = 0b00111000110110101110001010110100;
  src2.bits[2] = 0b10111011010111111101000100011110;
  src2.bits[3] = 0b10000000000010110000000000000000;
  int result = is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_12) {
  decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 1844674407370955161.50;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11111111111111111111111111110110;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00000000000000000000000000001001;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_13) {
  decimal src1, src2;
  int origin;
  // src1 = 44073709551615.0;
  // src2 = 44073709551615.00000000;
  src1.bits[0] = 0b00011010000001000111111111110110;
  src1.bits[1] = 0b00000000000000011001000011011001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b10011111010010100001111100000000;
  src2.bits[1] = 0b11101100100011110001010001110111;
  src2.bits[2] = 0b00000000000000000000000011101110;
  src2.bits[3] = 0b00000000000010000000000000000000;
  int result = is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_14) {
  decimal src1, src2;
  int origin;
  // src1 = 228162514264337.5935439503;
  // src2 = 228162514264337.59354395030000;
  src1.bits[0] = 0b01010010111101011100001010001111;
  src1.bits[1] = 0b00100101100101100010101000001101;
  src1.bits[2] = 0b00000000000000011110001100100111;
  src1.bits[3] = 0b00000000000010100000000000000000;
  src2.bits[0] = 0b10011111111111111111000111110000;
  src2.bits[1] = 0b00111001110010101010100001111000;
  src2.bits[2] = 0b01001001101110010010100100101100;
  src2.bits[3] = 0b00000000000011100000000000000000;
  int result = is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_15) {
  decimal src1, src2;
  int origin;
  // src1 = -754554545454658.97816770;
  // src2 = -754554545454658.9781677;
  src1.bits[0] = 0b00100000101101101001001011000010;
  src1.bits[1] = 0b01110010110010011000000011111000;
  src1.bits[2] = 0b00000000000000000000111111111010;
  src1.bits[3] = 0b10000000000010000000000000000000;
  src2.bits[0] = 0b10011100110111110000111010101101;
  src2.bits[1] = 0b00001011011110101000110011100101;
  src2.bits[2] = 0b00000000000000000000000110011001;
  src2.bits[3] = 0b10000000000001110000000000000000;
  int result = is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(test_equal_16) {
  decimal src1, src2;
  int origin;
  // src1 = -2.514264337593543;
  // src2 = -2.5142643375935430000000000000;
  src1.bits[0] = 0b11001000101101101011010011000111;
  src1.bits[1] = 0b00000000000010001110111010110101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b01010011100110100110000000000000;
  src2.bits[1] = 0b10000010110010001001101110001011;
  src2.bits[2] = 0b01010001001111011000000111010100;
  src2.bits[3] = 0b10000000000111000000000000000000;
  int result = is_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

Suite *test_is_equal(void) {
  Suite *s = suite_create("\033[45m-=is_equal=-\033[0m");
  TCase *tc = tcase_create("is_equal_tc");

  tcase_add_test(tc, test_equal_1);
  tcase_add_test(tc, test_equal_2);
  tcase_add_test(tc, test_equal_3);
  tcase_add_test(tc, test_equal_4);
  tcase_add_test(tc, test_equal_5);
  tcase_add_test(tc, test_equal_6);
  tcase_add_test(tc, test_equal_7);
  tcase_add_test(tc, test_equal_8);
  tcase_add_test(tc, test_equal_9);
  tcase_add_test(tc, test_equal_10);
  tcase_add_test(tc, test_equal_11);
  tcase_add_test(tc, test_equal_12);
  tcase_add_test(tc, test_equal_13);
  tcase_add_test(tc, test_equal_14);
  tcase_add_test(tc, test_equal_15);
  tcase_add_test(tc, test_equal_16);

  suite_add_tcase(s, tc);
  return s;
}