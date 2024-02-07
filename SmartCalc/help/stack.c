#include "header/stack.h"

calc_stack* create_stack() {
  bool is_error = false;
  calc_stack* newstack = (calc_stack*)calloc(1, sizeof(calc_stack));
  if (newstack == NULL) {
    is_error = true;
  } else {
    newstack->length = 0;
    newstack->tokens = (char**)calloc(MAX_LEN, sizeof(char**));
    if (newstack->tokens == NULL) {
      is_error = true;
    }
  }
  return is_error == 0 ? newstack : NULL;
}

bool is_stack_empty(calc_stack* stack) {
  if (stack == NULL) {
    return false;
  }
  return stack->length == 0;
}

bool is_stack_full(calc_stack* stack) {
  if (stack == NULL) {
    return false;
  }
  return stack->length == MAX_LEN;
}

void push(calc_stack* stack, char* token) {
  if (stack != NULL && !is_stack_full(stack) && token != NULL) {
    stack->tokens[stack->length] = token;
    stack->length++;
  }
}

char* peek(calc_stack* stack) {
  if (stack == NULL || is_stack_empty(stack)) {
    return NULL;
  }
  return stack->tokens[stack->length - 1];
}

char* pop(calc_stack* stack) {
  if (stack == NULL || is_stack_empty(stack)) {
    return NULL;
  }
  stack->length--;
  return stack->tokens[stack->length];
}

void remove_stack(calc_stack* stack) {
  if (stack != NULL && stack->tokens != NULL) {
    free(stack->tokens);
    stack->tokens = NULL;
    stack->length = 0;
  }
}

double_stack* create_double_stack() {
  double_stack* newstack = (double_stack*)calloc(1, sizeof(double_stack));
  if (newstack != NULL) {
    newstack->length = 0;
    newstack->values = (long double*)calloc(MAX_LEN, sizeof(long double*));
  }
  return newstack->values != NULL ? newstack : NULL;
}

bool is_double_stack_empty(double_stack* stack) {
  if (stack == NULL) {
    return false;
  }
  return stack->length == 0;
}

bool is_double_stack_full(double_stack* stack) {
  if (stack == NULL) {
    return false;
  }
  return stack->length == MAX_LEN;
}

void push_double(double_stack* stack, long double value) {
  if (stack != NULL && !is_double_stack_full(stack)) {
    stack->values[stack->length] = value;
    stack->length++;
  }
}

long double peek_double(double_stack* stack) {
  if (stack == NULL || is_double_stack_empty(stack)) {
    return 0;
  }
  return stack->values[stack->length - 1];
}

long double pop_double(double_stack* stack) {
  if (stack == NULL || is_double_stack_empty(stack)) {
    return 0;
  }
  stack->length--;
  return stack->values[stack->length];
}

void remove_double_stack(double_stack* stack) {
  if (stack != NULL && stack->values != NULL) {
    free(stack->values);
    stack->values = NULL;
    stack->length = 0;
  }
}
