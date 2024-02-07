/**
 *
 * @file validation.h
 *
 */
#ifndef VALIDATION_H
#define VALIDATION_H
#define _GNU_SOURSE_

#include "../../smart_calc.h"

/**
 * @brief Функция для перемещения по входной строке и поиска запрещенных
 * символов.
 * @param str указатель на входную строку
 * @return статус bool:
 * 1 - valid
 * 0 - eroor
 */
bool validation(char *str);

/**
 * @brief Функция проверяет все допустимые входные аргументы и определяет,
 * сколько места они занимают в строке
 * @param ptr указатель на аргумент
 * @return длина допустимых символов в строке
 */
int handle_symbols(char *ptr);

/**
 * @brief Функция проверяет, является ли точка действительным числом и является
 * ли она единственной.
 * @param str указатель на символ 'точка' в строке
 * @return статус bool:
 * 1 - valid
 * 0 - error
 */
bool check_is_dot_valid(char *str);

#endif
