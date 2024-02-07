#include "decimal.h"

int floor(decimal value, decimal *result) {
  int err = 1;
  if (result) {
    int sign = get_sign(value.bits[3]);
    initialize_decimal(result);
    decimal one = {{1, 0, 0, 0}};
    truncate(value, result);
    if (sign && is_not_equal(value, *result)) {
      add_value(*result, one, result);
    }
    result->bits[3] ^= (-sign ^ result->bits[3]) & (1U << 31);
    err = 0;
  }
  return err;
}