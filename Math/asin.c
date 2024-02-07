#include "smath.h"

long double asin(double x) {
  double res = 0;
  if (x == 1 || x == -1) {
    res = PI / (2 * x);
  } else if (x > -1 && x < 1) {
    res = PI / 2 - acos(x);
  } else {
    res = NAN;
  }
  return res;
}
