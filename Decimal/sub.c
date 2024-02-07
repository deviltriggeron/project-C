#include "decimal.h"

int sub(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;
  int sign1 = get_sign(value_1.bits[3]);
  int sign2 = get_sign(value_2.bits[3]);
  decimal_overflow val1 = {
      {value_1.bits[0], value_1.bits[1], value_1.bits[2], 0, 0, 0}};
  decimal_overflow val2 = {
      {value_2.bits[0], value_2.bits[1], value_2.bits[2], 0, 0, 0}};
  decimal_overflow res = {0};
  unsigned int scale =
      compare_and_set_exp(&val1, &val2, value_1.bits[3], value_2.bits[3]);
  value_1.bits[3] = clear_bit(value_1.bits[3], 31);
  value_2.bits[3] = clear_bit(value_2.bits[3], 31);
  scale = clear_bit(scale, 31);
  if (!sign1 && !sign2) {
    if (is_less(value_1, value_2)) {
      overflow_binary_subtraction(val2, val1, &res);
      scale |= MINUS;
    } else if (!is_equal(value_1, value_2)) {
      overflow_binary_subtraction(val1, val2, &res);
    }
  } else if (sign1 && !sign2) {
    overflow_binary_addition(val1, val2, &res);
    scale |= MINUS;
  } else if (!sign1 && sign2) {
    overflow_binary_addition(val1, val2, &res);
  } else {
    if (is_greater(value_1, value_2)) {
      overflow_binary_subtraction(val1, val2, &res);
      scale |= MINUS;
    } else if (!is_equal(value_1, value_2)) {
      overflow_binary_subtraction(val2, val1, &res);
    }
  }
  error = large_number_max(res, scale);
  if (result) {
    if (!error) {
      initialize_decimal(result);
      result->bits[3] = scale;
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
