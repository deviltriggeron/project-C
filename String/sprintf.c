#include "sstring.h"
#define LEN_ROW 1024

int mark_trailing_zero(char *array, int len);
int atoi(char *str);
int isdigit(char str);
int unsign(int n);
void put_to_buffer(char *buffer, char *array, struct Specifier *unit);
void int_to_octal(unsigned int num, char *array, struct Specifier *unit);
void int_to_hex(unsigned int value, char *hex, struct Specifier *unit);
void reverse_char_array(char *array, int len);
void insert_spaces(char *array, struct Specifier *unit);
void apply_plus_flag(char *array, struct Specifier *unit);
void apply_minus_flag(char *array, struct Specifier *unit);
void itoa(int n, char *array, struct Specifier *unit);
void ftoa(double n, char *array, int precision, struct Specifier *unit);
void utoa(unsigned int u, char *array, struct Specifier *unit);
void htoa(short n, char *array, struct Specifier *unit);
void ltoa(long int n, char *array, struct Specifier *unit);
void lutoa(unsigned long int u, char *array, struct Specifier *unit);
void hutoa(unsigned short int n, char *array, struct Specifier *unit);
int check_for_flags(char *format, int index, char *buffer,
                    struct Specifier *unit);
void append_head_zeroes(char *array, struct Specifier *unit);
void init_struct(struct Specifier *unit);

int sprintf(char *dest, char *format, ...) {
  struct Specifier sp = {0};

  va_list ap;

  int d = 0;
  int i = 0;
  unsigned int u = 0;
  unsigned long u_1 = 0;
  unsigned short u_2 = 0;
  long int d_1 = 0;
  short d_2 = 0;
  char *s = 0;
  char c = 0;
  char tmp_char[256] = {0};
  char complex_digit[256] = {0};
  char buffer[2096] = {0};

  double f = 0;
  va_start(ap, format);

  while (format[i]) {
    if (format[i] == '%') {
      init_struct(&sp);
      i = check_for_flags(format, i + 1, buffer, &sp);
      switch (format[i]) {
        case 's':
          sp.string++;
          s = va_arg(ap, char *);
          put_to_buffer(buffer, s, &sp);
          i++;
          break;
        case 'c':
          sp.c++;
          tmp_char[0] = va_arg(ap, int);
          put_to_buffer(buffer, tmp_char, &sp);
          i++;
          break;

        case 'd':
          if (sp.l == 1) {
            d_1 = va_arg(ap, long int);
            ltoa(d_1, complex_digit, &sp);
          } else if (sp.h == 1) {
            d_2 = va_arg(ap, int);
            hutoa(d_2, complex_digit, &sp);
          } else {
            d = va_arg(ap, int);
            itoa(d, complex_digit, &sp);
          }
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;

        case 'f':
          sp.f++;
          f = va_arg(ap, double);
          ftoa(f, complex_digit, sp.custom_precision, &sp);
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;

        case 'g':
          sp.g++;
          f = va_arg(ap, double);
          ftoa(f, complex_digit, sp.custom_precision, &sp);
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;

        case 'u':
          sp.u++;
          if (sp.l > 0) {
            u_1 = va_arg(ap, unsigned long int);
            lutoa(u_1, complex_digit, &sp);
          } else if (sp.h > 0) {
            u_2 = va_arg(ap, unsigned int);
            hutoa(u_2, complex_digit, &sp);
          } else {
            u = va_arg(ap, unsigned int);
            utoa(u, complex_digit, &sp);
          }
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;

        case 'o':
          d = va_arg(ap, int);
          u = (unsigned int)d;
          int_to_octal(u, complex_digit, &sp);
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;

        case 'X':
          sp.x++;
          d = va_arg(ap, int);
          u = (unsigned int)d;
          int_to_hex(u, complex_digit, &sp);
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;

        case 'x':
          d = va_arg(ap, int);
          u = (unsigned int)d;
          int_to_hex(u, complex_digit, &sp);
          put_to_buffer(buffer, complex_digit, &sp);
          i++;
          break;
        case '%':
          tmp_char[0] = '%';
          put_to_buffer(buffer, tmp_char, &sp);
          i++;
          break;

        default:
          break;
      }
    } else {
      c = format[i];
      strncat(buffer, &c, 1);
      i++;
    }
  }
  memcpy(dest, buffer, strlen(buffer));

  va_end(ap);
  return (int)strlen(buffer);
}

void reverse_char_array(char *array, int len) {
  int i = 0;
  char tmp = 0;

  for (i = 0; i < (len / 2); i++) {
    tmp = array[i];
    array[i] = array[len - i - 1];
    array[len - i - 1] = tmp;
  }
}

void itoa(int n, char *array, struct Specifier *unit) {
  int index = 0;
  int n_cpy = n;

  if (n == 0) {
    array[0] = (char)48;
    array[1] = '\0';
  }
  if (n < 0) {
    n *= -1;
    unit->digit_sign = 1;
  }

  while (n > 0) {
    array[index++] = n % 10 + '0';
    n /= 10;
  }

  unit->digit_len = strlen(array);

  if (unit->custom_precision > 0) {
    int spaces_to_put = unit->custom_precision - strlen(array);
    (spaces_to_put < 0) ? (spaces_to_put *= -1)
                        : (spaces_to_put = spaces_to_put);
    for (int j = 0; j < spaces_to_put; j++) {
      array[index++] = (char)48;
    }
  }

  if (n_cpy < 0 && unit->plus < 1) {
    array[index] = '-';
    index++;
  }

  reverse_char_array(array, strlen(array));
}

void ftoa(double n, char *array, int precision, struct Specifier *unit) {
  if (n < 0) {
    n *= -1;
    unit->digit_sign = 1;
  }

  int i = 0;
  int whole = 0;
  int decimal = 0;
  int index = 0;
  int dot_index = 0;
  (precision < 0) ? (precision = 6) : (precision = precision);
  double extract_whole = 0;
  double extract_decimal = modf(n, &extract_whole);
  if (unit->dot_f) {
    if (extract_decimal == 0 || !unit->custom_precision) {
      whole = (int)round(n);
      decimal = 0;
    } else {
      whole = (int)extract_whole;
      decimal = (int)(extract_decimal * pow(10, precision));
    }
  } else {
    whole = (int)extract_whole;
    decimal = (int)(extract_decimal * 1000000);
  }
  char temp_decimal[256] = {0};
  char temp_whole[256] = {0};

  while (whole > 0) {
    temp_whole[index++] = whole % 10 + '0';
    whole /= 10;
    dot_index++;
  }
  if (unit->digit_sign) {
    temp_whole[strlen(temp_whole)] = '-';
  }
  reverse_char_array(temp_whole, strlen(temp_whole));
  if (precision > 0) {
    temp_whole[strlen(temp_whole)] = '.';
  }
  while (decimal > 0) {
    temp_decimal[i] = (char)(decimal % 10 + '0');
    decimal /= 10;
    index++;
    i++;
  }
  reverse_char_array(temp_decimal, i);
  unit->digit_len = strlen(temp_whole) + strlen(temp_decimal);
  (unit->g > 0)
      ? (unit->zeroes_to_cut = mark_trailing_zero(temp_decimal, index))
      : (unit->zeroes_to_cut = 0);
  strncat(array, temp_whole, strlen(temp_whole));
  strncat(array, temp_decimal,
              strlen(temp_decimal) - unit->zeroes_to_cut);
}

int atoi(char *str) {
  int result = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (isdigit(str[i])) {
      result = result * 10 + str[i] - '0';
    }
  }
  return result;
}

int isdigit(char str) {
  if (str > 47 && str < 58) {
    return 1;
  } else {
    return 0;
  }
}

int mark_trailing_zero(char *array, int len) {
  int zeros_from_end = 0;

  for (int i = len, j = 0; i != 0; i--) {
    if (array[i] == '0') {
      j++;
      zeros_from_end++;
    }
  }
  return zeros_from_end;
}

void int_to_octal(unsigned int num, char *array, struct Specifier *unit) {
  int i = 0;

  while (num > 0) {
    array[i] = num % 8 + '0';
    num /= 8;
    i++;
  }

  unit->digit_len = strlen(array);
  apply_plus_flag(array, unit);
  reverse_char_array(array, strlen(array));
}

void int_to_hex(unsigned int value, char *hex, struct Specifier *unit) {
  char hexDigits[16] = {0};
  (unit->x > 0) ? strcpy(hexDigits, "0123456789ABCDEF")
                : strcpy(hexDigits, "0123456789abcdef");
  int index = 0;

  if (value == 0) {
    hex[0] = '0';
    hex[1] = '\0';
    return;
  }

  while (value != 0) {
    int digit = value & 0xF;
    hex[index] = hexDigits[digit];
    value >>= 4;
    index++;
  }

  int length = index;
  int i = 0;
  int j = length - 1;

  while (i < j) {
    char temp = hex[i];
    hex[i] = hex[j];
    hex[j] = temp;
    i++;
    j--;
  }

  hex[index] = '\0';

  unit->digit_len = strlen(hex);
}

void utoa(unsigned int u, char *array, struct Specifier *unit) {
  unsigned int counter = 0;

  if (u == 0) {
    array[counter++] = '0';
  }

  for (; u; u /= 10) {
    array[counter++] = u % 10 + '0';
  }
  unit->digit_len = strlen(array);
  reverse_char_array(array, counter);
  append_head_zeroes(array, unit);
}

void lutoa(unsigned long int u, char *array, struct Specifier *unit) {
  unsigned long int counter = 0;

  if (u == 0) {
    array[counter++] = '0';
  }

  for (; u; u /= 10) {
    array[counter++] = u % 10 + '0';
  }
  unit->digit_len = strlen(array);
  apply_plus_flag(array, unit);
  reverse_char_array(array, counter);
}

void apply_plus_flag(char *array, struct Specifier *unit) {
  int sign = unit->digit_sign;
  int arr_len = strlen(array);
  if (unit->plus > 0) {
    if (sign == 0) {
      reverse_char_array(array, arr_len);
      array[strlen(array)] = '+';
      reverse_char_array(array, arr_len + 1);
    } else if (sign == 1) {
      reverse_char_array(array, arr_len);
      array[arr_len] = '-';
      reverse_char_array(array, arr_len + 1);
    }
  }
  unit->digit_sign = 0;
}

void insert_spaces(char *array, struct Specifier *unit) {
  (unit->minus) ? (unit->flag_space = 0) : (unit->minus);

  if (unit->spaces > 0) {
    reverse_char_array(array, strlen(array));
    for (int j = strlen(array); j < unit->spaces; j++) {
      array[j] = (char)32;
    }
    reverse_char_array(array, strlen(array));
  }
}

void apply_minus_flag(char *array, struct Specifier *unit) {
  if (unit->minus > 0) {
    for (int j = strlen(array); j < unit->minus; j++) {
      array[j] = (char)32;
    }
  }
}
void put_to_buffer(char *buffer, char *array, struct Specifier *unit) {
  if (unit->string || unit->c) {
    char tmp_string[1024] = {0};
    strncpy(tmp_string, array, strlen(array));
    if (!unit->minus) {
      insert_spaces(tmp_string, unit);
    }
    apply_minus_flag(tmp_string, unit);
    strncat(buffer, tmp_string, strlen(tmp_string));
  } else {
    if (!unit->u) {
      apply_plus_flag(array, unit);
    }
    if (!unit->minus) {
      insert_spaces(array, unit);
    }
    apply_minus_flag(array, unit);
    strncat(buffer, array, strlen(array));
    memset(array, 0, 256);
  }
  unit->flag_trail = 0;
}

int check_for_flags(char *format, int index, char *buffer,
                    struct Specifier *unit) {
  int i = index;
  int k = 0;
  int pass_i = 0;
  char tmp_spaces_len[256] = {0};
  char tmp_precision[256] = {0};
  const char SPECS[9] = {'s', 'c', 'd', 'f', 'g', 'u', 'o', 'x', 'X'};

  for (int j = 0; format[i] != SPECS[j] && j < 9; j++) {
    if (isdigit(format[i])) {
      while (isdigit(format[i]) != 0) {
        tmp_spaces_len[k++] = format[i++];
      }
      unit->spaces += atoi(tmp_spaces_len);
      k = 0;
    }

    if (format[i] == '.') {
      unit->dot_f = 1;
      while (isdigit(format[i += 1]) != 0) {
        tmp_precision[k++] = format[i];
      }
      unit->custom_precision = atoi(tmp_precision);
    }

    if (format[i] == '+') {
      unit->plus++;
      if (isdigit(format[i += 1])) {
        while (isdigit(format[i]) != 0) {
          tmp_spaces_len[k++] = format[i++];
        }
        unit->spaces += atoi(tmp_spaces_len);
        k = 0;
      }
    }

    if (format[i] == '-') {
      if (format[i + 1] == ' ') {
        i++;
      }
      if (isdigit(format[i += 1])) {
        while (isdigit(format[i]) != 0) {
          tmp_spaces_len[k++] = format[i++];
        }
        unit->minus += atoi(tmp_spaces_len);
        k = 0;
      } else {
        unit->minus += 1;
        // i++;
      }
    }

    if (format[i] == ' ') {
      if (!unit->minus) {
        for (int j = 0; format[j] != '\0'; j++) {
          if (format[j] == '%' &&
              (format[j + 1] != ' ' || format[j + 2] != ' ')) {
            pass_i = 1;
          }
        }
        if (pass_i != 1) {
          unit->flag_space = 1;
          while (format[i] == ' ') {
            i++;
          }
          strncat(buffer, " ", 1);
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    if (format[i] == 'h') {
      unit->h = 1;
      i++;
    }
    if (format[i] == 'l') {
      unit->l = 1;
      i++;
    }
  }
  return i;
}

void init_struct(struct Specifier *unit) {
  unit->custom_precision = -1;
  unit->zeroes_to_cut = 0;
  unit->digit_sign = 0;
  unit->digit_len = 0;
  unit->flag_space = 0;
  unit->spaces = 0;
  unit->g = 0;
  unit->f = 0;
  unit->x = 0;
  unit->c = 0;
  unit->l = 0;
  unit->plus = 0;
  unit->minus = 0;
  unit->string = 0;
  unit->h = 0;
  unit->u = 0;
  unit->dot_f = 0;
  unit->flag_trail = 1;
}

void ltoa(long n, char *array, struct Specifier *unit) {
  int index = 0;
  long int n_cpy = n;

  if (n < 0) {
    n *= -1;
    unit->digit_sign = 1;
  }

  while (n > 0) {
    array[index++] = n % 10 + '0';
    n /= 10;
  }
  unit->digit_len = strlen(array);

  append_head_zeroes(array, unit);

  if (n_cpy < 0 && unit->plus < 1) {
    array[index] = '-';
    index++;
  }

  reverse_char_array(array, strlen(array));
}

void hutoa(unsigned short n, char *array, struct Specifier *unit) {
  int index = 0;

  while (n > 0) {
    array[index++] = n % 10 + '0';
    n /= 10;
  }

  unit->digit_len = strlen(array);

  append_head_zeroes(array, unit);

  reverse_char_array(array, strlen(array));
}

void htoa(short n, char *array, struct Specifier *unit) {
  int index = 0;
  short n_cpy = n;

  if (n < 0) {
    n *= -1;
    unit->digit_sign = 1;
  }

  while (n > 0) {
    array[index++] = n % 10 + '0';
    n /= 10;
  }

  unit->digit_len = strlen(array);
  append_head_zeroes(array, unit);

  if (n_cpy < 0 && unit->plus < 1) {
    array[index] = '-';
    index++;
  }

  reverse_char_array(array, strlen(array));
}

void append_head_zeroes(char *array, struct Specifier *unit) {
  char tmp_[256] = {0};
  if (unit->custom_precision > 0) {
    int spaces_to_put = unit->custom_precision - strlen(array);
    (spaces_to_put < 0) ? (spaces_to_put *= -1)
                        : (spaces_to_put = spaces_to_put);
    for (int j = 0; j < spaces_to_put; j++) {
      tmp_[j] = (char)48;
    }
    strncat(tmp_, array, strlen(array));
    strncpy(array, tmp_, strlen(tmp_));
  }
}
