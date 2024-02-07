#include "smart_calc.h"

int calc_str(const char* str, long double* res) {
  if (str == NULL || res == NULL) return ERROR;
  *res = 0;
  char input_data[MAX_LEN + 1] = {'\0'};
  bool error = false;
  strncpy(input_data, str, MAX_LEN);
  error = !validation(input_data);
  if (!error) {
    char* token_str = divider(input_data);
    if (token_str != NULL) {
      missing_mult_signs_handler(token_str);
      add_end_of_line(token_str);
      error = !dijkstra(token_str);
      if (!error) {
        *res = calculate_res(token_str);
      }
      free(token_str);
      token_str = NULL;
    }
  }
  return error;
}

int calc_notation(const char* str, char* res_str) {
  if (str == NULL || res_str == NULL) return ERROR;
  char input_data[MAX_LEN + 1] = {'\0'};
  bool error = false;
  strncpy(input_data, str, MAX_LEN);
  error = !validation(input_data);
  if (!error) {
    char* token_str = divider(input_data);
    if (token_str != NULL) {
      missing_mult_signs_handler(token_str);
      add_end_of_line(token_str);
      x_replacement_to_value(token_str, 2);
      error = !dijkstra(token_str);
      if (!error) {
        strncpy(res_str, token_str, MAX_LEN * 2);
      }
      free(token_str);
      token_str = NULL;
    }
  }
  return error;
}

int calc_with_x(const char* str, long double x, long double* res) {
  if (str == NULL || res == NULL) return ERROR;
  *res = 0;
  char input_data[MAX_LEN + 1] = {'\0'};
  bool error = false;
  strncpy(input_data, str, MAX_LEN);
  error = !validation(input_data);
  if (!error) {
    char* token_str = divider(input_data);
    if (token_str != NULL) {
      missing_mult_signs_handler(token_str);
      add_end_of_line(token_str);
      x_replacement_to_value(token_str, x);
      error = !dijkstra(token_str);
      if (!error) {
        *res = calculate_res(token_str);
      }
      free(token_str);
      token_str = NULL;
    }
  }
  return error;
}

// int main () {
//     char *input = "-2+3";
//     long double res = 0;
//     calc_str(input, &res);
//     printf("result--->%Lf\n", res);
//     printf("calc_str->%s", input);
//     return 0;
// }