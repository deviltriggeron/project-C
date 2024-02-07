#include "decimal.h"

int mul(decimal value_1, decimal value_2, decimal *result) {
  int error = 0;
  if (result) {
    decimal_overflow res = {{0, 0, 0, 0, 0, 0}};
    for (int i = 0; i < 96; i++) {
      if (check_bit_state(value_1.bits[i / 32], i % 32)) {
        decimal_overflow tmp = {{0, 0, 0, 0, 0, 0}};
        copy_overflow(&tmp, res);
        overflow_binary_addition(tmp, left_n_times_overflow(value_2, i),
                                     &res);
      }
    }
    unsigned int scale =
        get_exp(value_1.bits[3]) || get_exp(value_2.bits[3])
            ? ((get_exp(value_1.bits[3]) + get_exp(value_2.bits[3]))
               << 16)
            : 0;
    if ((get_sign(value_1.bits[3]) ^ get_sign(value_2.bits[3])))
      scale |= MINUS;

    error = large_number_max(res, scale);
    if (!error) {
      initialize_decimal(result);
      result->bits[3] = scale;
      normalize_to_lower_exp(res, result);
      while (check_divisible_by_10(*result) &&
             get_exp(result->bits[3]) != 0) {
        divide_by_10(result);
        result->bits[3] -= 1 << 16;
      }
      if (check_zero(*result) && get_exp(result->bits[3]) >= 28) {
        error = 1;
        initialize_decimal(result);
      }
    }
  }
  return error;
}
