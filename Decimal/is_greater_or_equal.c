#include "decimal.h"

int is_greater_or_equal(decimal number1, decimal number2) {
  return !is_less(number1, number2);
}