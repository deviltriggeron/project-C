#include "smath.h"

long double acos(double x) {
  long double res = 0;
  if (x < 1 && x >= 0) {
    res = atan(sqrt(1 - x * x) / x);
  } else if (x < 0 && x > -1) {
    res = PI + atan(sqrt(1 - x * x) / x);
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = PI;
  } else {
    res = NAN;
  }
  return res;
}
