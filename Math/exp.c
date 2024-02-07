#include "smath.h"

long double exp(double x) {
  long double value = 1;
  long double res = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  if (x != x) {
    res = NAN;
  } else {
    while (fabs(value) > EPS) {
      value = value * (x / i);
      i = i + 1;
      res = res + value;
      if (res > LDBL_MAX || x >= 709.782713) {
        res = INF_PLUS;
        break;
      }
    }
  }
  if (flag == 1) {
    if (res > LDBL_MAX || x >= 14.508658) {
      res = 0;
    } else {
      res = 1. / res;
    }
  }
  return res;
}
