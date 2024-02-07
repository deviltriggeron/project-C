#include "decimal.h"

int is_less_or_equal(decimal number1, decimal number2) {
  return !is_greater(number1, number2);
}
