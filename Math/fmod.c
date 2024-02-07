#include "smath.h"

long double fmod(double x, double y) {
  long double res = 0;
  long long int value = 0;
  if (y == 0 || x == NAN || x == INF_MINUS || x == INF_PLUS) {
    res = NAN;
  } else {
    value = x / y;
    res = x - (value * y);
  }
  return res;
}
