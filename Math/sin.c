#include "smath.h"

int signbit(double x) {
  unsigned long long *bits = (unsigned long long *)&x;
  return (*bits >> 63) & 1;
}

long double sin(double x) {
  int flag = 0;
  long double result = 0;
  long double member = 0;
  long double ex_pow = 1;

  if (x == INF_PLUS || x == INF_MINUS || x != x) {
    result = NAN;
  }

  if (signbit(x) == 1 && x == 0.0) {
    result = -0.0;
    flag++;
  } else if (signbit(x) == 0 && x == 0.0) {
    result = 0.0;
    flag++;
  }

  if (flag == 0) {
    x = fmod(x, 2 * PI);
    member = x;
    while (fabs(member) > EPS) {
      result += member;
      ex_pow += 2;
      member = -member * (x * x) / (ex_pow * (ex_pow - 1));
    }
  }
  return result;
}
