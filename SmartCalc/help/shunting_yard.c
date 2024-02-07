#include "header/shunting_yard.h"

bool dijkstra(char *str) {
  if (str == NULL) {
    return false;
  }
  bool status = true;
  char buffer[MAX_LEN * 2 + 1] = {'\0'};
  calc_stack *workstack = create_stack();
  if (workstack != NULL) {
    char *token = strtok(str, " ");
    int allowed_len = MAX_LEN * 2;
    while (token != NULL && status && allowed_len - (int)strlen(token) > 0) {
      status = dijkstra_logic(token, workstack, buffer);
      token = strtok(NULL, " ");
      if (token != NULL) {
        allowed_len -= (int)strlen(token) + 1;
      }
    }
    remove_stack(workstack);
    free(workstack);
    workstack = NULL;
    strncpy(str, buffer, MAX_LEN * 2);
  } else {
    status = false;
  }

  return status;
}

bool dijkstra_logic(char *token, calc_stack *calc_stack, char *buffer) {
  if (token == NULL || calc_stack == NULL || buffer == NULL) {
    return false;
  }
  bool status = true;
  if (strchr("0123456789.x", (int)*token)) {
    strcat(buffer, token);
    strcat(buffer, " ");
  } else if (strchr(OPERATORS, (int)*token)) {
    if (peek(calc_stack) != NULL) {
      decide_on_priority(token, calc_stack, buffer);
    } else {
      push(calc_stack, token);
    }
  } else if (strchr(FUNC, (int)*token) || strchr("~p", (int)*token)) {
    push(calc_stack, token);
  } else if (*token == '(') {
    push(calc_stack, token);
  } else if (*token == ')') {
    decide_on_closure_brackets(calc_stack, buffer, status);
  } else if (*token == '<') {
    status = handle_EOL(calc_stack, buffer);
  }

  return status;
}

int check_priority(int priority_code) {
  int priority = 0;

  if (priority_code == '(') {
    priority = OPEN_BRACKET;
  } else if (priority_code == '+') {
    priority = PLUS;
  } else if (priority_code == '-') {
    priority = MINUS;
  } else if (priority_code == '*') {
    priority = MULT;
  } else if (priority_code == '/') {
    priority = DIV;
  } else if (priority_code == '^') {
    priority = POW;
  } else if (priority_code == 'm') {
    priority = DIV;
  }

  return priority;
}

int get_operator_int(char *token) {
  if (token == NULL) {
    return 0;
  }
  return (int)*token;
}

bool handle_EOL(calc_stack *calc_stack, char *buffer) {
  if (calc_stack == NULL || buffer == NULL) {
    return false;
  }
  bool res = true;
  bool has_unclosed_brackets = false;
  while (peek(calc_stack) != NULL && !has_unclosed_brackets) {
    if (*(peek(calc_stack)) == '(') {
      has_unclosed_brackets = true;
    } else {
      strcat(buffer, pop(calc_stack));
      strcat(buffer, " ");
    }
  }
  if (has_unclosed_brackets) {
    res = false;
  }
  return res;
}

void decide_on_priority(char *token, calc_stack *calc_stack, char *buffer) {
  if (token != NULL && calc_stack != NULL && buffer != NULL) {
    int cur_priority = get_operator_int(token);
    int priority_from_stack = get_operator_int(peek(calc_stack));
    int current_priority = check_priority(cur_priority);

    if (current_priority > check_priority(priority_from_stack) ||
        (current_priority == 3 && check_priority(priority_from_stack) == 3)) {
      push(calc_stack, token);
    } else {
      bool is_stack_empty_or_priority_less = false;
      while (!is_stack_empty_or_priority_less) {
        priority_from_stack = get_operator_int(peek(calc_stack));
        if (current_priority <= check_priority(priority_from_stack) &&
            priority_from_stack) {
          strcat(buffer, pop(calc_stack));
          strcat(buffer, " ");
        } else {
          push(calc_stack, token);
          is_stack_empty_or_priority_less = true;
        }
      }
    }
  }
}

void decide_on_closure_brackets(calc_stack *calc_stack, char *buffer,
                                bool status) {
  if (calc_stack != NULL && buffer != NULL) {
    bool has_open_pair = false;
    bool is_end = false;

    while (!is_end && status) {
      if (peek(calc_stack) != NULL) {
        if (*(peek(calc_stack)) != '(') {
          strcat(buffer, pop(calc_stack));
          strcat(buffer, " ");
        } else {
          has_open_pair = true;
          pop(calc_stack);
          is_end = true;
        }
      } else {
        is_end = true;
      }
    }
    if (!has_open_pair) {
      status = false;
    }
  }
}
