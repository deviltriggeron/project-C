#include "smath.h"

int isnan(double x) { return (x != x); }

long double pow_int(double base, int exp) {
  long double integer = 1;
  if (exp > 0) {
    for (int i = 0; i < exp; i++) {
      integer = integer * base;
    }
  } else {
    for (int i = 0; i < (-1) * exp; i++) {
      integer = integer / base;
    }
  }
  return integer;
}

long double pow(double base, double exp) {
  long double res = 0;
  int flag = 0;
  if ((base == 1 && exp != isnan(exp)) ||
      (base == 1 && exp == INF_PLUS) ||
      (base == 1 && exp == INF_MINUS)) {
    res = 1.0;
    flag++;
  } else if ((base == -1 && exp == INF_MINUS) ||
             (base == -1 && exp == INF_PLUS) || (exp == 0)) {
    res = 1.0;
    flag++;
  } else if ((base == INF_MINUS && exp - (int)exp != 0 && exp > 0) ||
             (base < 0 && exp == INF_PLUS)) {
    res = INF_PLUS;
    flag++;
  } else if ((base < 0 && exp - (int)exp != 0 && exp > 0) &&
             (exp != INF_PLUS) && (exp != INF_MINUS)) {
    res = NAN;
    flag++;
  } else if (base > 1 && exp >= 1024) {
    res = INF_PLUS;
    flag++;
  }
  if (flag == 0) {
    if (base < 0) {
      base = -base;
      res = exp(exp * log(base));
      if (exp - (int)exp == 0 && fmod(exp, 2) != 0) {
        res = -res;
      }
    } else if (exp == (int)exp) {
      res = pow_int(base, (int)exp);
    } else {
      res = exp(exp * log(base));
    }
    if (res == INF_MINUS && base < 0) {
      res = -res;
    }
  }
  return res;
}
