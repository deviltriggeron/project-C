#include "smath.h"

long double log(double x) {
  int n = 0;
  double y = (x - 1) / (x + 1);
  double term = 2 * y;
  double res = term;
  if (x == 0) {
    res = INF_MINUS;
  } else if (x < 0) {
    res = NAN;
  } else if (x == INF_PLUS) {
    res = INF_PLUS;
  } else {
    while (fabs(term) >= 0.000000000001) {
      ++n;
      term *= (2 * n - 1) * y * y / (2 * n + 1);
      res += term;
    }
  }
  return res;
}
