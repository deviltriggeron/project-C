#include "smath.h"

long double atan(double x) {
  long double res = x, num = x, r = 1;
  int i = 1;
  res = x > -1 && x < 1 ? x : 1 / x;
  if (x == 1) {
    res = 0.7853981633974483;
  } else if (x == -1) {
    res = -0.7853981633974483;
  } else {
    while (fabs(r) > EPS) {
      num *= -1 * x * x;
      if (x >= -1 && x <= 1) {
        r = num / (2 * i + 1);
      } else {
        r = 1 / (num * (2 * i + 1));
      }
      res += r;
      i++;
    }
    if (!(x > -1 && x < 1) && x > 0) {
      res = (PI / 2) - res;
    } else if (!(x > -1 && x < 1) && x < 0) {
      res = -(PI / 2) - res;
    }
  }
  return res;
}
