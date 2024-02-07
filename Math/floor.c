#include "smath.h"

long double floor(double x) {
  long double res = 0, value = x;
  int remainder = x;
  if (x == INF_PLUS) {
    res = INF_PLUS;
  } else if (x == INF_MINUS) {
    res = INF_MINUS;
  } else if (x >= 0) {
    res = remainder;
  } else if (x < 0) {
    value = value - remainder;
    if (value == 0) {
      res = remainder;
    } else {
      res = remainder - 1;
    }
  } else {
    res = NAN;
  }
  return res;
}
