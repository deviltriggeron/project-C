#include "sstring.h"

char *strchr(const char *str, int c) {
  if (c == 0) {
    return "";
  }
  char *result = NULL;
  if (c != '\0') {
    for (; *str != '\0'; str++) {
      if (*str == c) {
        result = (char *)str;
        break;
      }
    }
  }
  return result;
}