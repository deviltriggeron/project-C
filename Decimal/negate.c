#include "decimal.h"

int negate(decimal value, decimal *result) {
  int err = 1;
  if (result) {
    *result = value;
    result->bits[3] ^= 1U << 31;
    err = 0;
  }
  return err;
}