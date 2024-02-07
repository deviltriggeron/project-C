#include "decimal.h"

int truncate(decimal value, decimal *result) {
  int error = 1;
  if (result) {
    int sign = get_sign(value.bits[3]);
    int exp = get_exp(value.bits[3]);
    for (; exp > 0; exp--) {
      divide_by_10(&value);
    }
    set_exp(&value.bits[3], exp);
    assign_value(result, value);
    result->bits[3] ^= (-sign ^ result->bits[3]) & (1U << 31);
    error = 0;
  }
  return error;
}
