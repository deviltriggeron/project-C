#ifndef DECIMAL
#define DECIMAL
#define _GNU_SOURSE_

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[6];
} decimal_overflow;

typedef struct {         // bits[0] младшие 32 бита
  unsigned int bits[4];  // bits[1] средние 32 бита
} decimal;           // bits[2] старшие 32 бита

union Data {
  int i;
  float f;
};

int divide_by_10(decimal *value);
int check_bit_state(int number, int index);
int set_bit(int number, int index);
int invert_bit(int number, int index);
int clear_bit(int number, int index);
void initialize_decimal(decimal *dst);
int absolute_value(int number);
int get_sign(int number);
int get_exp(int number);

int overflow_binary_addition(decimal_overflow value_1,
                                 decimal_overflow value_2,
                                 decimal_overflow *result);
void initialize_overflow(decimal_overflow *dst);
void copy_overflow(decimal_overflow *number1, decimal_overflow number2);
void left_overflow(decimal_overflow *value);
void right(decimal_overflow *value);
decimal_overflow left_n_times_overflow(decimal number, int shift);

int left(decimal *value);
int left_n_times(decimal *number, int shift);
void print_binary_overflow(decimal_overflow number);
void print_int_overflow(decimal_overflow number);
void print_binary(int number);
int check_overflow(decimal_overflow *number);
unsigned int set_mask(int shift);
void print_binary_dec(decimal number);
void print_int_dec(decimal number);
int compare_and_set_exp(decimal_overflow *num_1, decimal_overflow *num_2,
                            unsigned int scale_1, unsigned int scale_2);
void normalization(decimal_overflow *result, short scale);
void assign_value(decimal *number1, decimal number2);
int check_zero(decimal number);
int add_value(decimal value_1, decimal value_2,
                  decimal *result);
void set_exp(unsigned *scale, unsigned target);
int check_divisible_by_10(decimal n);
int multiply_value(decimal value_1, decimal value_2,
                       decimal *result);
void subtract_binary(decimal value_1, decimal value_2,
                         decimal *result);
int round_off_float(double num);
int get_sign_float(double num);
int get_exp_float(double num);
decimal_overflow multiply_large_numbers(decimal_overflow value_1,
                                        decimal_overflow value_2);
int first_large_number_greater(decimal_overflow number1,
                                   decimal_overflow number2);
decimal_overflow overflow_shift_left_n_times(decimal_overflow number,
                                             int shift);
int overflow_binary_subtraction(decimal_overflow value_1,
                                    decimal_overflow value_2,
                                    decimal_overflow *result);
int large_number_max(decimal_overflow val_1, int scale);
void normalize_to_lower_exp(decimal_overflow value, decimal *result);
int overflow_value_zero(decimal_overflow number);
int divide_by_10_overflow(decimal_overflow *n);
void bank_round(decimal_overflow value, decimal_overflow *result);
void mod10(decimal_overflow value, decimal_overflow *mod);
int dividing(decimal val1, decimal val2, decimal_overflow *result);
int find_exp(decimal_overflow res, decimal_overflow celoe);
int find_down(decimal_overflow res, decimal_overflow celoe);
void up_exp(decimal_overflow *v1, int diff1);
decimal_overflow bin_div(decimal_overflow v1, decimal_overflow v2);
int check_divisible_by_10_overflow(decimal_overflow n);
int overflow_is_equal(decimal_overflow number1, decimal_overflow number2);
int overflow_is_less_or_equal(decimal_overflow number1,
                                  decimal_overflow number2);
void right(decimal_overflow *value);
void compare_exp(decimal_overflow *num_1, decimal_overflow *num_2,
                     unsigned int *scale_1, unsigned int *scale_2);

// Arithmetic Operators
int add(decimal value_1, decimal value_2, decimal *result);
int sub(decimal value_1, decimal value_2, decimal *result);
int mul(decimal value_1, decimal value_2, decimal *result);
int div(decimal value_1, decimal value_2, decimal *result);

// Comparison Operators
int is_less(decimal, decimal);  // дичь какаято
int is_less_or_equal(decimal, decimal);
int is_greater(decimal, decimal);
int is_greater_or_equal(decimal, decimal);
int is_equal(decimal, decimal);
int is_not_equal(decimal, decimal);

// Convertors and parsers
int from_int_to_decimal(int src, decimal *dst);
int from_float_to_decimal(float src, decimal *dst);
int from_decimal_to_int(decimal src, int *dst);
int from_decimal_to_float(decimal src, float *dst);

// Another functions
int floor(decimal value, decimal *result);
int round(decimal value, decimal *result);
int truncate(decimal value, decimal *result);
int negate(decimal value, decimal *result);

/*
Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который
указывает степень 10 для разделения целого числа. Биты с 24 по 30 не
используются и должны быть равны нулю. Бит 31 содержит знак; 0 означает
положительный, а 1 означает отрицательный.
*/

#define MINUS 2147483648
#define EXP_INT_MASK 8355840
#define MASK_FLOAT_EXP 1069547520
#define MAX_DEC 4294967295

#endif