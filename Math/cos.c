#include "smath.h"

long double cos(double x) {
  long double result = 0;
  result = sin(PI / 2 - x);
  return result;
}
