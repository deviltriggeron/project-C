#include "decimal.h"

int from_decimal_to_float(decimal src, float *dst) {
  int err = 1;
  if (dst) {
    err = 0;
    long double res = 0;
    int exp = get_exp(src.bits[3]);
    int sign = get_sign(src.bits[3]);

    for (int i = 0; i < 94; i++) {
      if (check_bit_state(src.bits[i / 31], i % 31)) {
        res += powl(2, i);
      }
    }
    for (; exp > 0; exp--) {
      res /= 10.0L;
    }
    *dst = sign ? -res : res;
  }
  return err;
}
