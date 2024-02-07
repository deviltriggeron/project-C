#include "decimal.h"

int round(decimal value, decimal *result) {
  int err = 1;
  if (result) {
    int sign = get_sign(value.bits[3]);
    decimal one = {{1, 0, 0, 0}};
    decimal ten = {{10, 0, 0, 0}};
    decimal tmp;
    decimal mod;
    assign_value(&tmp, value);
    int scaleMask = get_exp(value.bits[3]);
    while (scaleMask > 1) {
      divide_by_10(&tmp);
      scaleMask--;
    }
    if (scaleMask == 1) {
      assign_value(&value, tmp);
      divide_by_10(&tmp);
      multiply_value(tmp, ten, &tmp);
      subtract_binary(value, tmp, &mod);
      divide_by_10(&value);
      if (mod.bits[0] > 4) add_value(value, one, &value);
      scaleMask--;
      set_exp(&(value.bits[3]), scaleMask);
    }
    assign_value(result, value);
    result->bits[3] ^= (-sign ^ result->bits[3]) & (1U << 31);
    err = 0;
  }
  return err;
}
