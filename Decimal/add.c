#include "decimal.h"

int add(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;

  if (result) {
    int sign1 = get_sign(value_1.bits[3]);
    int sign2 = get_sign(value_2.bits[3]);

    decimal_overflow val1 = {
        {value_1.bits[0], value_1.bits[1], value_1.bits[2], 0, 0, 0}};
    decimal_overflow val2 = {
        {value_2.bits[0], value_2.bits[1], value_2.bits[2], 0, 0, 0}};
    decimal_overflow res = {0};

    unsigned int exp =
        compare_and_set_exp(&val1, &val2, value_1.bits[3], value_2.bits[3]);
    exp &= ~(1U << 31);
    if ((sign1 ^ sign2) == 0) {
      overflow_binary_addition(val1, val2, &res);
    } else {
      if (is_less(value_1, value_2)) {
        overflow_binary_subtraction(val2, val1, &res);
      } else if (!s21_is_equal(value_1, value_2)) {
        overflow_binary_subtraction(val1, val2, &res);
      }
    }

    if (sign1 && sign2) exp |= MINUS;

    error = large_number_max(res, exp);
    if (!error) {
      initialize_decimal(result);
      result->bits[3] = exp;
      normalize_to_lower_exp(res, result);
      while (check_divisible_by_10(*result) &&
             get_exp(result->bits[3]) != 0) {
        divide_by_10(result);
        result->bits[3] -= 1 << 16;
      }
    }
  }
  return error;
}