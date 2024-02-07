#include "decimal.h"

int from_int_to_decimal(int src, decimal *dst) {
  int err = 1;
  if (dst) {
    initialize_decimal(dst);
    err = 0;
    if (src < 0) dst->bits[3] = MINUS;
    dst->bits[0] = absolute_value(src);
  }
  return err;
}