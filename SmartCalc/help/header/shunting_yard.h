/**
 *
 * @file shunting_yard.h
 *
 */
#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#define _GNU_SOURSE_

#include "../../smart_calc.h"
#include "calculate.h"
#include "stack.h"

enum operator_precedence {
  OPEN_BRACKET,
  PLUS,
  MINUS = 1,
  MULT,
  DIV = 2,
  POW,
  UNARY_MINUS,
  UNARY_PLUS = 4,
};

/**
 * @brief Разделяет заданную строку на токены и отправляет их алгоритму Дейкстры
 * @param str указатель на строку с токенами
 * @return BOOL:
 * 0 - failure
 * 1 - success
 */
bool dijkstra(char *str);

/**
 * @brief Принимает решение относительно токена в соответствии с алгоритмом
 * shunting-yard
 * @param token текущий токен
 * @param calc_stack указатель на стек
 * @param buffer указатель на буфер вывода
 * @return BOOL:
 * 0 - failure
 * 1 - success
 */
bool dijkstra_logic(char *token, calc_stack *calc_stack, char *buffer);

/**
 * @brief Функция выполняет необходимые действия с оператором в зависимости от
 * наличия других операторов в стеке
 * @param token текущий токен (оператор)
 * @param calc_stack указатель на стек
 * @param buffer указатель на буфер вывода
 */
void decide_on_priority(char *token, calc_stack *calc_stack, char *buffer);

/**
 * @brief Функция обрабатывает логику действий при закрывающей скобке
 * @param calc_stack указатель на стек
 * @param buffer указатель на буфер вывода
 * @param is_success указатель на флаг ошибки
 */
void decide_on_closure_brackets(calc_stack *calc_stack, char *buffer,
                                bool status);

/**
 * @brief Инициирует действия в алгоритме при достижении конца строки
 * @param calc_stack указатель на стек
 * @param buffer указатель на буфер вывода
 * @return BOOL:
 * 0 - failure
 * 1 - success
 */
bool handle_EOL(calc_stack *calc_stack, char *buffer);

/**
 * @brief Получает первый символ токена, в нашем случае - сокращенную версию
 * оператора
 * @param token указатель на текущий токен
 * @return int оператор
 */
int get_operator_int(char *token);

/**
 * @brief Функция проверяет приоритет оператора
 * @return приоритет оператора
 */
int check_priority(int operator_code);

#endif
