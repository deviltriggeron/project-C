#include "sstring.h"

char *strncat(char *dest, const char *src, size_t n) {
  size_t i = 0;
  char *p = dest + strlen(dest);

  while (*src != '\0' && i != n) {
    *p++ = *src;
    src++;
    i++;
  }

  p = '\0';

  return dest;
}
