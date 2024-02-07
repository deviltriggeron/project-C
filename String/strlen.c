#include "sstring.h"

size_t strlen(const char *str) {
  size_t i = 0;
  if (str) {
    for (; str[i] != '\0'; i++)
      ;
  }
  return i;
}