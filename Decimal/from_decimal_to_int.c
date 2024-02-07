#include "decimal.h"

int from_decimal_to_int(decimal src, int *dst) {
  int err = 1;
  if (dst) {
    err = 0;
    int sign = get_sign(src.bits[3]);
    truncate(src, &src);
    if (src.bits[2] == 0 && src.bits[1] == 0 && src.bits[0] <= 2147483648) {
      err = (!sign && src.bits[0] == 2147483648) ? 1 : 0;
    } else {
      err = 1;
    }
    *dst = (!err) ? ((sign ? -1 : 1) * (int)(src.bits[0])) : 0;
  }
  return err;
}