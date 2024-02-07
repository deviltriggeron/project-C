#include "sstring.h"

char *strpbrk(const char *str1, const char *str2) {
  while (*str1 != '\0') {
    const char *c = str2;
    while (*c != '\0') {
      if (*str1 == *c) {
        return (char *)str1;
      }
      c++;
    }
    str1++;
  }
  return NULL;
}
