#include "decimal.h"

int is_equal(decimal number1, decimal number2) {
  int result = 1;
  decimal_overflow num_1 = {{number1.bits[0], number1.bits[1], number1.bits[2],
                             0, 0, 0}},
                   num_2 = {{number2.bits[0], number2.bits[1], number2.bits[2],
                             0, 0, 0}};
  compare_and_set_exp(&num_1, &num_2, number1.bits[3], number2.bits[3]);
  if (get_sign(number1.bits[3]) == get_sign(number2.bits[3])) {
    int i = 5;
    while (result && i >= 0) {
      result = (num_1.bits[i] == num_2.bits[i]);
      i--;
    }
  } else {
    result = check_zero(number1) && check_zero(number2);
  }
  return result;
}