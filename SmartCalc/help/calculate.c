#include "header/calculate.h"

long double calculate_res(char *str) {
  if (str == NULL) {
    return false;
  }

  char temp[MAX_LEN + 1] = {'\0'};
  strncpy(temp, str, MAX_LEN);
  long double result = 0;
  bool error = false;
  double_stack *calculation_stack = create_double_stack();
  if (calculation_stack != NULL) {
    char *token = strtok(temp, " ");
    while (token != NULL && !error) {
      error = !calculation(token, calculation_stack, &result);
      token = strtok(NULL, " ");
    }
    result = pop_double(calculation_stack);
    remove_double_stack(calculation_stack);
    free(calculation_stack);
    calculation_stack = NULL;
  } else {
    error = true;
  }
  return error == 0 ? result : NAN;
}

bool calculation(char *token, double_stack *calculation_stack,
                 long double *result) {
  if (token == NULL || calculation_stack == NULL || result == NULL) {
    return false;
  }

  bool status = true;
  if (strchr("0123456789.", (int)*token)) {
    push_double(calculation_stack, strtold(token, &token));
  } else if (strchr(OPERATORS, (int)*token)) {
    long double res = 0;
    status = calculate_f_stack(calculation_stack, &res, (int)*token);
    if (status) {
      push_double(calculation_stack, res);
    }
  } else if (*token == '~') {
    push_double(calculation_stack, 0 - pop_double(calculation_stack));
  } else if (*token == 'p') {
    push_double(calculation_stack, 0 + pop_double(calculation_stack));
  } else {
    long double res = 0;
    status = func(token, calculation_stack, &res);
    if (status) {
      push_double(calculation_stack, res);
    }
  }
  return status;
}

bool calculate_f_stack(double_stack *calculation_stack, long double *res,
                       int sign) {
  if (calculation_stack == NULL || res == NULL) {
    return false;
  }

  long double val1 = pop_double(calculation_stack);
  long double val2 = pop_double(calculation_stack);
  if (sign == '+') {
    *res = val2 + val1;
  } else if (sign == '-') {
    *res = val2 - val1;
  } else if (sign == '*') {
    *res = val2 * val1;
  } else if (sign == '/') {
    *res = val2 / val1;
  } else if (sign == '^') {
    *res = powl(val2, val1);
  } else if (sign == 'm') {
    *res = fmod(val2, val1);
  }
  return isnan(*res) == 0 ? true : false;
}

bool func(char *func, double_stack *stack, long double *res) {
  if (func == NULL || stack == NULL || res == NULL) {
    return ERROR;
  }
  long double value = pop_double(stack);

  if (strstr(func, "sin")) {
    *res = sinl(value);
  }
  if (strstr(func, "cos")) {
    *res = cosl(value);
  }
  if (strstr(func, "tan")) {
    *res = tanl(value);
  }
  if (strstr(func, "asin")) {
    *res = asinl(value);
  }
  if (strstr(func, "acos")) {
    *res = acosl(value);
  }
  if (strstr(func, "atan")) {
    *res = atanl(value);
  }
  if (strstr(func, "sqrt")) {
    *res = sqrtl(value);
  }
  if (strstr(func, "ln")) {
    *res = logl(value);
  }
  if (strstr(func, "log")) {
    *res = log10l(value);
  }
  // if(strstr(func, "mod")) {
  //   *res = fabsl(value);
  // }
  return isnan(*res) == 0 ? true : false;
}
