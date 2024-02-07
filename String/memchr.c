#include "sstring.h"

void *memchr(const void *str, int c, size_t n) {
  const unsigned char *p = str;

  for (size_t i = 0; i < n; i++, p++) {
    if (*p == (unsigned char)c) {
      return (void *)p;
    }
  }
  return NULL;
}