/**
 *
 * @file smart_calc.h
 *
 */
#ifndef SMART_CALC_H
#define SMART_CALC_H
#define _GNU_SOURSE_

#include <float.h>
#include <iso646.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255
#define ALL_SYMBOLS "0123456789()+-*/^msctalx."
#define NUMBERS "0123456789"
#define FUNC "sctal"
#define NUMB "1234567890.e"
#define OPERATORS "+-*/^m"
#define BRACKET "()"

#include "help/header/calculate.h"
#include "help/header/credit_calc.h"
#include "help/header/divider.h"
#include "help/header/shunting_yard.h"
#include "help/header/stack.h"
#include "help/header/validation.h"

enum code_result { OK, ERROR };

/**
 * @brief Основная функция выполняющая все действия для вычесления
 * математического выражения
 *
 * @param str Строка с математическим выражением
 *
 * @param res Результат вычесления математического выражения
 *
 * @return bool значение 0-SUCCESS, 1-FALSE
 */
int calc_str(const char* str, long double* res);
/**
 * @brief Функция преобразует обычную инфиксную запись в обратную польскую
 запись (или постфиксную).

 * @param str Строка с математическим выражением

 * @param res Результат вычесления математического выражения
 *
 * @return bool значение 0-SUCCESS, 1-FALSE
 */
int calc_notation(const char* str, char* res_str);
/**
 * @brief Изменение основной функции, заменяющей неизвестные значения x
 заданными значениями и записывающей результат в переменную.

 * @param str Строка с математическим выражением

 * @param x Значение для неизвестной переменной (X)

 * @param res Результат вычесления математического выражения
 *
 * @return bool значение 0-SUCCESS, 1-FALSE
 */
int calc_with_x(const char* str, long double x, long double* res);

#endif
