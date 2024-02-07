#include "smath.h"

long double tan(double x) {
  long double result = 0.0;
  result = sin(x) / cos(x);
  return result;
}