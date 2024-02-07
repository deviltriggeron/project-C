#include "sstring.h"

void *memcpy(void *dest, const void *src, size_t n) {
  char *copy_dest = (char *)dest;
  const char *copy_src = (char *)src;

  for (size_t i = 0; i < n; i++) {
    copy_dest[i] = copy_src[i];
  }

  return dest;
}