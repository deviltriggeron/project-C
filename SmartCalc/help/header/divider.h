/**
 *
 * @file divider.h
 *
 */
#ifndef TOKEN_H
#define TOKEN_H
#define _GNU_SOURSE_

#include "../../smart_calc.h"
#include "stack.h"

/**
 * @brief Функция разделяет строки на токены, разделенные пробелами.
 *
 * @param str Указатель на входную строку.
 *
 * @return Указатель на новую строку допустимых токенов.
 *
 */
char *divider(char *token);

/**
 * @brief The function checks if the character 'e' is exponential notation
 * @param str pointer to the 'e' character
 * @return bool value:
 * 1 - EXP NOTATION
 * 0 - NO
 */
bool check_exp_notation(char *str);

/**

* @brief Функция проверяет длину числа, записанного в экспоненциальной
* нотации
* @param str указатель на число в экспоненциальной нотации
* @return длина числа, записанного экспоненциально
*/
int exp_notation_length(char *str);

/**
 * @brief Проверяет функции и возвращает их длину в строке
 * @param ptr Указатель на математическую функцию
 * @return Количество символов математической функции
 */
int handle_functions(char *ptr);

/**
 * @brief Функция добавляет отсутствующие знаки умножения к строке
 * @param str указатель на строку математических токенов
 */
void missing_mult_signs_handler(char *str);

/**
 * @brief Функция устанавливает последний символ строки математических токенов
 * в знак '<' для последующих вычислений
 * @param str указатель на строку математических токенов
 */
void add_end_of_line(char *str);

/**
 * @brief
Функция итерируется по строке и заменяет все 'X' на входное значение типа long
double
 * @param str указатель на входную строку
 * @param value значение типа long double для замены 'X'
 */
void x_replacement_to_value(char *str, long double value);

#endif