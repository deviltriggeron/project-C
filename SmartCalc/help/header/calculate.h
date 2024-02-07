/**
 *
 * @file calculate.h
 *
 */
#ifndef CALCULATE_H
#define CALCULATE_H
#define _GNU_SOURSE_

#include "../../smart_calc.h"
#include "stack.h"

/**
 * @brief Функция передает токены в функцию вычисления и вычисляет конечный
 * результат согласно алгоритму вычисления обратной польской записи.
 * @param str Указатель на строку с токенами.
 * @return long double value - конечный результат
 */
long double calculate_res(char *str);
/**
 * @brief Функция вычисления для calculate_res
 * @param token указатель на текущий математический токен
 * @param calculation_stack указатель на стек вычислений
 * @param result указатель на результирующее значение long double
 * @return bool значение
 * 0 - failure
 * 1 - success
 */
bool calculation(char *token, double_stack *calculation_stack,
                 long double *result);
/**
 * @brief Выполняет основные арифметические операции
 * @param calculation_stack указатель на стек вычислений
 * @param res указатель на результирующее значение long double
 * @param sign входящий оператор
 * @return bool значение 0 - NUMBER is NaN 1 - Number is finite
 */
bool calculate_f_stack(double_stack *calculation_stack, long double *res,
                       int sign);
/**
 * @brief Выполняет вычисление всех основных тригонометрических функций
 * @param calculation_stack указатель на стек вычислений
 * @param res указатель на результирующее значение long double
 * @param func текущая тригонометрическая функция
 * @return bool значение
 * 0 - NUMBER is NaN
 * 1 - Number is finite
 */
bool func(char *func, double_stack *stack, long double *res);

#endif
