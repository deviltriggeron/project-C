#include "decimal.h"

int check_bit_state(int num, int idx) { return (num & (1 << idx)) != 0; }

int set_bit(int num, int idx) { return (num | (1 << idx)); }

int invert_bit(int num, int idx) { return (num ^ (1 << idx)); }

int clear_bit(int num, int idx) { return (num & ~(1 << idx)); }

int left(decimal *value) {
  short upper_bits[3] = {0};
  int result_status = 0;
  for (int i = 0; i < 3; i++)
    upper_bits[i] = check_bit_state(value->bits[i], 31);
  if (upper_bits[2] == 0) {
    for (int i = 0; i < 3; i++) value->bits[i] <<= 1;
    for (int i = 0; i < 2; i++)
      if (upper_bits[i])
        value->bits[i + 1] = set_bit(value->bits[i + 1], 0);
  } else
    result_status = 1;
  return result_status;
}

int left_n_times(decimal *value, int times) {
  int result_status = 0;
  for (int i = 0; i < times && !result_status; i++)
    result_status = left(value);
  return result_status;
}

void left_overflow(decimal_overflow *value) {
  short b[5];
  for (int i = 0; i < 5; i++) b[i] = check_bit_state(value->bits[i], 31);
  for (int i = 0; i < 6; i++) value->bits[i] <<= 1;
  for (int i = 0; i < 5; i++)
    if (b[i]) value->bits[i + 1] = set_bit(value->bits[i + 1], 0);
}

decimal_overflow overflow_left_n_times(decimal_overflow number, int shift) {
  for (int i = 0; i < shift; i++) left_overflow(&number);
  return number;
}

decimal_overflow left_n_times_overflow(decimal number, int shift) {
  decimal_overflow res = {
      {number.bits[0], number.bits[1], number.bits[2], 0, 0, 0}};
  for (int i = 0; i < shift; i++) left_overflow(&res);
  return res;
}

void right(decimal_overflow *value) {
  short lower_bits[5];
  for (int i = 1; i < 5; i++)
    lower_bits[i] = check_bit_state(value->bits[i], 0);
  for (int i = 0; i < 6; i++) value->bits[i] >>= 1;
  for (int i = 4; i > 0; i--)
    if (lower_bits[i]) value->bits[i - 1] = set_bit(value->bits[i - 1], 31);
}

decimal_overflow bin_div(decimal_overflow v1, decimal_overflow v2) {
  decimal_overflow l = {0}, r = v1, mid = {0};

  decimal_overflow tmp = {0};
  decimal_overflow one = {{1, 0, 0, 0, 0, 0}};
  decimal_overflow res = {0};
  while (overflow_is_less_or_equal(l, r)) {
    overflow_binary_subtraction(r, l, &tmp);

    right(&tmp);
    overflow_binary_addition(l, tmp, &mid);
    tmp = multiply_large_numbers(v2, mid);
    if (first_large_number_greater(tmp, v1)) {
      overflow_binary_subtraction(mid, one, &r);
    } else {
      copy_overflow(&res, mid);
      overflow_binary_addition(mid, one, &l);
    }
  }
  return res;
}

int absolute_value(int num) { return (num < 0) ? -num : num; }

int get_sign(int num) { return check_bit_state(num, 31); }

int get_exp(int num) {
  int result = num & EXP_INT_MASK;
  result = result >> 16;
  return result;
}

int check_zero(decimal num) {
  for (int i = 0; i < 3; i++) {
    if (num.bits[i] != 0) {
      return 0;
    }
  }
  return 1;
}

int add_value(decimal num1, decimal num2, decimal *result) {
  int carry = 0;
  int sum;
  initialize_decimal(result);
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      sum = check_bit_state(num1.bits[j], i) +
            check_bit_state(num2.bits[j], i) + carry;
      if (sum >= 2) {
        carry = 1;
      } else {
        carry = 0;
      }
      if (sum % 2 == 1) {
        result->bits[j] = set_bit(result->bits[j], i);
      }
    }
    if (carry && j == 2) return 1;
  }
  return carry;
}

int multiply_value(decimal value_1, decimal value_2,
                       decimal *result) {
  int status = 0;
  decimal temp = {0};
  decimal res = {0};
  decimal val1_cp = {0};
  if (result) {
    for (int i = 0; i < 96 && !status; i++) {
      if (check_bit_state(value_2.bits[i / 32], i % 32)) {
        initialize_decimal(&temp);
        assign_value(&val1_cp, value_1);
        assign_value(&temp, res);
        status =
            left_n_times(&val1_cp, i) + add_value(temp, val1_cp, &res);
      }
    }
    if (status == 0) assign_value(result, res);
  }
  return status;
}

int divide_by_10(decimal *decimal_num) {
  unsigned int remainder = 0;
  long long int temporary;
  for (int i = 2; i >= 0; --i) {
    temporary = (unsigned)decimal_num->bits[i] + ((long long)(remainder) << 32);
    remainder = temporary % 10;
    decimal_num->bits[i] = temporary / 10;
  }
  return remainder;
}

void subtract_binary(decimal value_1, decimal value_2,
                         decimal *result) {
  for (int i = 0; i < 96; i++)
    value_2.bits[i / 32] = invert_bit(value_2.bits[i / 32], i);
  value_2.bits[0]++;
  add_value(value_1, value_2, result);
}

int overflow_binary_subtraction(decimal_overflow value_1,
                                    decimal_overflow value_2,
                                    decimal_overflow *result) {
  int err;
  if (!overflow_value_zero(value_2)) {
    for (int i = 0; i < 192; i++)
      value_2.bits[i / 32] = invert_bit(value_2.bits[i / 32], i);
    value_2.bits[0]++;
  }
  err = overflow_binary_addition(value_1, value_2, result);
  return err;
}

int overflow_value_zero(decimal_overflow number) {
  int isZero = 1;
  for (int i = 0; i < 6; i++) {
    if (number.bits[i] != 0) {
      isZero = 0;
    }
  }
  return isZero;
}

int overflow_binary_addition(decimal_overflow value_1,
                                 decimal_overflow value_2,
                                 decimal_overflow *result) {
  short error = 0, mind = 0;
  int term1, term2;
  initialize_overflow(result);
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 32; i++) {
      term1 = check_bit_state(value_1.bits[j], i);
      term2 = check_bit_state(value_2.bits[j], i);
      if (term1 && term2) {
        if (mind) {
          result->bits[j] = set_bit(result->bits[j], i);
        } else {
          mind = 1;
        }
      } else if (term1 ^ term2) {
        if (!mind) {
          result->bits[j] = set_bit(result->bits[j], i);
        }
      } else if (mind) {
        result->bits[j] = set_bit(result->bits[j], i);
        mind = 0;
      }
    }
    if (mind && j == 5) error = 1;
  }
  return error;
}

void set_exp(unsigned *scale, unsigned target) {
  unsigned sign = get_sign(*scale);
  *scale = target;
  *scale <<= 16;
  if (sign) *scale = set_bit(*scale, 31);
}

int check_divisible_by_10(decimal n) {
  decimal temp_num = {0};
  for (int i = 0; i < 3; ++i) temp_num.bits[i] = n.bits[i];
  return !divide_by_10(&temp_num);
}

int get_exp_float(double floating_num) {
  union Data float_data;
  float_data.f = floating_num;
  int exponent = (float_data.i & MASK_FLOAT_EXP) >> 23;
  exponent = exponent - 127;

  return exponent;
}

int get_sign_float(double floating_num) {
  union Data float_data;
  float_data.f = floating_num;
  int sign = check_bit_state(float_data.i, 31);
  return sign;
}

int round_off_float(double floating_num) {
  int result;
  double integral_part, fractional_part;
  fractional_part = modf(floating_num, &integral_part);

  if (fractional_part > 0.5) integral_part += 1;
  result = (int)integral_part;

  return result;
}

int compare_and_set_exp(decimal_overflow *num_1, decimal_overflow *num_2,
                            unsigned int scale_1, unsigned int scale_2) {
  int flag = 0;
  if (get_exp(scale_1) > get_exp(scale_2)) {
    normalization(num_2, get_exp(scale_1) - get_exp(scale_2));
    flag = scale_2 = scale_1;
  } else if (get_exp(scale_1) < get_exp(scale_2)) {
    normalization(num_1, get_exp(scale_2) - get_exp(scale_1));
    flag = scale_1 = scale_2;
  } else {
    flag = scale_1;
  }
  return flag;
}

void normalization(decimal_overflow *result, short scale) {
  decimal_overflow ten = {{10, 0, 0, 0, 0, 0}};
  for (int i = 0; i < scale; i++) {
    *result = multiply_large_numbers(*result, ten);
  }
}

void normalize_to_lower_exp(decimal_overflow input_value,
                                decimal *output_result) {
  while (input_value.bits[3] || input_value.bits[4] || input_value.bits[5] ||
         (get_exp(output_result->bits[3]) > 28)) {
    bank_round(input_value, &input_value);
    output_result->bits[3] -= 1 << 16;
  }
  output_result->bits[0] = input_value.bits[0];
  output_result->bits[1] = input_value.bits[1];
  output_result->bits[2] = input_value.bits[2];
}

int check_divisible_by_10_overflow(decimal_overflow n) {
  decimal_overflow tmp = {0};
  for (int i = 0; i < 6; ++i) tmp.bits[i] = n.bits[i];
  return !divide_by_10_overflow(&tmp);
}

int divide_by_10_overflow(decimal_overflow *n) {
  unsigned int mod = 0;
  long long int tmp;
  for (int i = 5; i >= 0; --i) {
    tmp = (unsigned)n->bits[i] + ((long long)(mod) << 32);
    mod = tmp % 10;
    n->bits[i] = tmp / 10;
  }
  return mod;
}

void bank_round(decimal_overflow value, decimal_overflow *result) {
  if (result) {
    initialize_overflow(result);
    decimal_overflow mod1, mod2;
    initialize_overflow(&mod1);
    initialize_overflow(&mod2);
    decimal_overflow one = {{1, 0, 0, 0, 0, 0}};
    mod10(value, &mod1);
    divide_by_10_overflow(&value);
    if (mod1.bits[0] > 5) {
      overflow_binary_addition(value, one, &value);
    } else if (mod1.bits[0] == 5) {
      mod10(value, &mod2);
      if (mod2.bits[0] % 2 != 0)
        overflow_binary_addition(value, one, &value);
    }
  }
  *result = value;
}

void mod10(decimal_overflow value, decimal_overflow *mod) {
  decimal_overflow ten = {{10, 0, 0, 0, 0, 0}};
  decimal_overflow tmp = value;
  if (mod) {
    divide_by_10_overflow(&tmp);
    tmp = multiply_large_numbers(tmp, ten);
    overflow_binary_subtraction(value, tmp, mod);
  }
}

int dividing(decimal val1, decimal val2, decimal_overflow *result) {
  decimal_overflow val_1 = {{val1.bits[0], val1.bits[1], val1.bits[2], 0, 0,
                             0}},
                   val_2 = {{val2.bits[0], val2.bits[1], val2.bits[2], 0, 0,
                             0}},
                   my_integer = {0}, v1cpy = val_1, v2cpy = val_2;
  decimal one = {{1, 0, 0, 0}};
  decimal_overflow big_one = {{1, 0, 0, 0, 0, 0}};
  int ans = get_exp(val1.bits[3]);

  if (!is_equal(val2, one)) {
    int scale1 = get_exp(val1.bits[3]);
    int scale2 = get_exp(val2.bits[3]);
    int up =
        (scale1 != scale2) ? 28 + absolute_value(scale1 - scale2) - 1 : 29;
    compare_exp(&v1cpy, &v2cpy, &val1.bits[3], &val2.bits[3]);

    my_integer = bin_div(v1cpy, v2cpy);
    if (scale1 != scale2) {
      if (is_less(val1, val2) && !is_equal(val2, one)) {
        up_exp(&val_1, up);
      } else if (!is_equal(val2, one))
        up_exp(&val_1, 29);
    } else if (!is_equal(val2, one))
      up_exp(&val_1, 28);
    *result = bin_div(val_1, val_2);
    int scale = find_down(*result, my_integer);
    int down = scale <= 28 ? scale : 28;
    while ((check_overflow(result) && down > 0) ||
           (check_divisible_by_10_overflow(*result) && down > 0)) {
      bank_round(*result, result);
      down--;
    }
    ans = find_exp(*result, my_integer);
  } else {
    *result = bin_div(val_1, big_one);
  }
  return ans;
}

int find_exp(decimal_overflow res, decimal_overflow my_integer) {
  int scale = 0;
  int down = 28;
  while (!overflow_is_equal(res, my_integer) && down > 0) {
    divide_by_10_overflow(&res);
    scale++;
    down--;
  }
  return scale;
}

int find_down(decimal_overflow res, decimal_overflow my_integer) {
  int scale = 0;
  int down = 28;
  while (!overflow_is_equal(res, my_integer) && down >= 0) {
    divide_by_10_overflow(&res);
    scale++;
    down--;
  }
  return scale;
}

void up_exp(decimal_overflow *v1, int diff1) {
  decimal_overflow ten = {{10, 0, 0, 0, 0, 0}};

  while (diff1) {
    *v1 = multiply_large_numbers(*v1, ten);
    diff1--;
  }
}

decimal_overflow multiply_large_numbers(decimal_overflow value_1,
                                        decimal_overflow value_2) {
  decimal_overflow tmp = {{0, 0, 0, 0, 0, 0}};
  decimal_overflow res = {{0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 192; i++) {
    if (check_bit_state(value_1.bits[i / 32], i % 32)) {
      initialize_overflow(&tmp);
      copy_overflow(&tmp, res);
      overflow_binary_addition(tmp, overflow_left_n_times(value_2, i),
                                   &res);
    }
  }
  return res;
}

int first_large_number_greater(decimal_overflow number1,
                                   decimal_overflow number2) {
  int result = 0, flag = 0;
  for (int j = 5; j >= 0 && !result; j--) {
    unsigned int value1 = number1.bits[j];
    unsigned int value2 = number2.bits[j];
    if (!flag) {
      if (value1 > value2)
        result = 1;
      else if (value1 < value2)
        flag++;
    }
  }
  return result;
}

int large_number_max(decimal_overflow val_1, int scale) {
  decimal_overflow max = {{MAX_DEC, MAX_DEC, MAX_DEC, 0, 0, 0}};
  int err = 0;
  for (int i = 0; i < get_exp(scale); i++) {
    divide_by_10_overflow(&val_1);
  }
  if (first_large_number_greater(val_1, max)) {
    err = get_sign(scale) ? 2 : 1;
  }
  return err;
}

int overflow_is_equal(decimal_overflow number1, decimal_overflow number2) {
  int result = 1;
  for (int i = 5; i >= 0; i--) {
    unsigned int value1 = number1.bits[i];
    unsigned int value2 = number2.bits[i];
    if (value1 != value2) {
      result = 0;
    }
  }
  return result;
}

int overflow_is_less_or_equal(decimal_overflow number1,
                                  decimal_overflow number2) {
  return !first_large_number_greater(number1, number2);
}

void compare_exp(decimal_overflow *num_1, decimal_overflow *num_2,
                     unsigned int *scale_1, unsigned int *scale_2) {
  if (get_exp(*scale_1) > get_exp(*scale_2)) {
    normalization(num_2, get_exp(*scale_1) - get_exp(*scale_2));
    *scale_2 = *scale_1;
  } else if (get_exp(*scale_1) < get_exp(*scale_2)) {
    normalization(num_1, get_exp(*scale_2) - get_exp(*scale_1));
    *scale_1 = *scale_2;
  }
}

void initialize_decimal(decimal *dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0;
  }
}

void initialize_overflow(decimal_overflow *ovfl) {
  for (int i = 0; i < 6; i++) {
    ovfl->bits[i] = 0;
  }
}

void copy_overflow(decimal_overflow *dest, decimal_overflow src) {
  for (int i = 0; i < 6; i++) {
    dest->bits[i] = src.bits[i];
  }
}

int check_overflow(decimal_overflow *number) {
  return (number->bits[3] || number->bits[4] || number->bits[5]);
}

void assign_value(decimal *target, decimal source) {
  for (int i = 0; i < 4; i++) {
    target->bits[i] = source.bits[i];
  }
}