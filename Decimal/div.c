#include "decimal.h"

int div(decimal value_1, decimal value_2, decimal *result) {
  int err = check_zero(value_2) ? 3 : 0;
  if (err == 0 && result) {
    int sign = check_bit_state(value_1.bits[3], 31) ^
               check_bit_state(value_2.bits[3], 31);
    decimal_overflow res = {0};
    unsigned int scale = dividing(value_1, value_2, &res);
    if (check_overflow(&res)) err = sign ? 2 : 1;
    if (err == 0) {
      for (int i = 0; i < 3; i++) {
        result->bits[i] = res.bits[i];
      }
      result->bits[3] = (scale << 16) | (sign << 31);
    }
  }
  return err;
}