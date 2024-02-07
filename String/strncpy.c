#include "sstring.h"

char *strncpy(char *dest, const char *src, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (n < strlen(src)) {
      dest[i] = src[i];
    } else {
      dest[i] = src[i];
      if (i == strlen(src)) {
        while (i < n) {
          dest[i] = '\0';
          i++;
        }
      }
    }
  }
  return dest;
}