#include "header/validation.h"

bool validation(char* str) {
  if (str == NULL) {
    return false;
  } else if (*str == 'e' || *str == ')') {
    return false;
  }
  int status = true;
  for (char* ptr = str; *ptr != '\0' && status; ptr++) {
    char cur_char = *ptr;
    if (strchr(ALL_SYMBOLS, (int)cur_char) != NULL) {
      if (strchr(NUMBERS, (int)cur_char) || cur_char == 'x') {
        // its okay
      } else {
        int step = handle_symbols(ptr);
        if (step) {
          ptr += step - 1;
        } else {
          status = false;
        }
      }
    } else {
      status = false;
    }
  }
  return status;
}

int handle_symbols(char* ptr) {
  if (ptr == NULL) {
    return 0;
  }

  int valid_symbols = 0;
  char str_to_analyze[6] = {'\0'};
  strncat(str_to_analyze, ptr, 5);
  if (*ptr == '(') {
    valid_symbols = 1;
  } else if (*ptr == ')') {
    if (*(ptr - 1) != '(') {
      valid_symbols = 1;
    }
  } else if (*ptr == '.') {
    valid_symbols = (int)check_is_dot_valid(ptr);
  } else if (strchr("+-*/^m", (int)*ptr)) {
    if (strchr(ALL_SYMBOLS, (int)*(ptr + 1)) && *(ptr + 1) != '\0') {
      valid_symbols = 1;
    }
  } else if (*ptr == 'a') {
    if (strstr(str_to_analyze, "asin(") || strstr(str_to_analyze, "acos(") ||
        strstr(str_to_analyze, "atan(")) {
      valid_symbols = 5;
    }
  } else if (*ptr == 'c') {
    if (strstr(str_to_analyze, "cos(")) {
      valid_symbols = 4;
    }
  } else if (*ptr == 'l') {
    if (strstr(str_to_analyze, "ln(")) {
      valid_symbols = 3;
    } else if (strstr(str_to_analyze, "log(")) {
      valid_symbols = 4;
    }
  } else if (*ptr == 'm') {
    valid_symbols = 4;
  } else if (*ptr == 's') {
    if (strstr(str_to_analyze, "sin(")) {
      valid_symbols = 4;
    } else if (strstr(str_to_analyze, "sqrt(")) {
      valid_symbols = 5;
    }
  } else if (*ptr == 't') {
    if (strstr(str_to_analyze, "tan(")) {
      valid_symbols = 4;
    }
  }

  return valid_symbols;
}

bool check_is_dot_valid(char* str) {
  if (str == NULL) {
    return false;
  }

  bool has_significant = strchr(NUMBERS, (int)*(str - 2)) ? true : false;
  bool is_dot_single = true;
  bool is_only_numbers = true;
  str++;
  if (!has_significant && (!strchr(NUMBERS, (int)*(str)) || *(str) == '\0')) {
    is_dot_single = false;
  }
  for (char* ptr = str; *ptr != '\0' && is_dot_single && is_only_numbers;
       ptr++) {
    char cur_char = *ptr;
    if (!strchr(NUMBERS, (int)cur_char)) {
      is_only_numbers = false;
      if (cur_char == '.') {
        is_dot_single = false;
      }
    }
  }

  return is_dot_single;
}
