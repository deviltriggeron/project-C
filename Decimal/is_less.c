#include "decimal.h"

int is_less(decimal number1, decimal number2) {
  return is_greater(number2, number1);
}