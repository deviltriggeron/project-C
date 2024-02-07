#include "smath.h"

long double ceil(double x) {
  long double result = 0;
  int value = x;
  if (x == INF_PLUS) {
    result = INF_PLUS;
  } else if (x == INF_MINUS) {
    result = INF_MINUS;
  } else if (x == (int)x) {
    result = x;
  } else if (x > 0) {
    result = value + 1;
  } else if (x <= 0) {
    result = value;
  } else {
    result = NAN;
  }
  return result;
}
