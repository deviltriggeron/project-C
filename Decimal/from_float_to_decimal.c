#include "decimal.h"

int from_float_to_decimal(float src, decimal *dst) {
  int err = 1;
  int scale = 0;
  double srcd = (double)src;
  int sign = get_sign_float(srcd);
  if (dst && isfinite(srcd)) {
    err = 0;
    initialize_decimal(dst);
    int exp = get_exp_float(srcd);
    if (exp <= 95) {
      if (srcd != 0) {
        while (!truncf(srcd)) {
          srcd *= 10;
          scale += 1;
        }
        if (scale <= 28) {
          while (!truncf(srcd / 1000000) && scale < 28) {
            srcd *= 10;
            scale += 1;
          }
          srcd = fabs(srcd);
          srcd = round_off_float(srcd);
          dst->bits[0] = srcd;
          while (check_divisible_by_10(*dst)) {
            divide_by_10(dst);
            scale--;
          }
          dst->bits[3] = scale << 16;
          dst->bits[3] = sign ? set_bit(dst->bits[3], 31)
                              : clear_bit(dst->bits[3], 31);
        } else {
          err = 1;
        }
      }
    } else {
      err = 1;
    }
  }

  return err;
}