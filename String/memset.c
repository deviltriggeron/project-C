#include "sstring.h"

void *memset(void *str, int c, size_t n) {
  unsigned char *p = str;

  while (n--) {
    *p++ = (unsigned char)c;
  }
  return str;
}
