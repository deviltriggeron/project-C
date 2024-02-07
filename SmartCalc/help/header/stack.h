/**
 *
 * @file stack.h
 *
 */
#ifndef STACK_H
#define STACK_H
#define _GNU_SOURSE_

typedef struct stack_struct {
  int length;
  char **tokens;
} calc_stack;

typedef struct double_stack_struct {
  int length;
  long double *values;
} double_stack;

#include "../../smart_calc.h"

/**
 * @brief Инициализирует стек. Необходим вызов free() после использования.
 * Возвращает NULL в случае ошибки.
 * @return указатель на созданный стек || NULL
 */
calc_stack *create_stack();

/**
 * @brief Проверяет, является ли стек пустым
 * @param stack указатель на стек
 * @return BOOL:
 * 0 - stack not empty
 * 1 - stack empty
 */
bool is_stack_empty(calc_stack *stack);

/**
 * @brief Проверяет, является ли стек полным
 * @param stack указатель на стек
 * @return BOOL:
 * 0 - stack not full
 * 1 - stack full
 */
bool is_stack_full(calc_stack *stack);

/**
 * @brief Помещает char* в стек
 * @param stack указатель на стек
 * @param token char* математический токен
 */
void push(calc_stack *stack, char *token);

/**
 * @brief Получает верхнее значение стека, не удаляя его оттуда
 * @param stack указатель на стек
 * @return Верхнее значение на стеке
 */
char *peek(calc_stack *stack);

/**
 * @brief Получает верхнее значение стека и удаляет его оттуда
 * @param stack указатель на стек
 * @return Верхнее значение на стеке
 */
char *pop(calc_stack *stack);

/**
 * @brief Устанавливает длину стека в ноль и очищает выделенную память для
 * значений внутри него
 * @param stack указатель на стек
 */
void remove_stack(calc_stack *stack);

/**
 * @brief Инициализирует стек. Необходим вызов free() после использования.
 * Возвращает NULL в случае ошибки.
 * @return указатель на созданный стек || NULL
 */
double_stack *create_double_stack();

/**
 * @brief Проверяет, является ли стек пустым
 * @param stack указатель на стек
 * @return BOOL:
 * 0 - stack not empty
 * 1 - stack empty
 */
bool is_double_stack_empty(double_stack *stack);

/**
 * @brief Проверяет, является ли стек полным
 * @param stack указатель на стек
 * @return BOOL:
 * 0 - stack not full
 * 1 - stack full
 */
bool is_double_stack_full(double_stack *stack);

/**
 * @brief Помещает значение типа long double в стек
 * @param stack указатель на стек
 * @param value значение типа long double
 */
void push_double(double_stack *stack, long double values);

/**
 * @brief Получает верхнее значение стека, не удаляя его оттуда
 * @param stack указатель на стек
 * @return Верхнее значение на стеке
 */
long double peek_double(double_stack *stack);

/**
 * @brief Получает верхнее значение стека и удаляет его оттуда
 * @param stack указатель на стек
 * @return Верхнее значение на стеке
 */
long double pop_double(double_stack *stack);

/**
 * @brief Устанавливает длину стека в ноль и очищает выделенную память для
 * значений внутри него
 * @param stack указатель на стек
 */
void remove_double_stack(double_stack *stack);

#endif
