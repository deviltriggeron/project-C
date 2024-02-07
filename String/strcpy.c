#include "sstring.h"

void *strcpy(char *dest, char *src) {
  char temp_char = 0;

  for (size_t i = 0; i < strlen(src); i++) {
    temp_char = src[i];
    dest[i] = temp_char;
  }

  dest[strlen(src)] = '\0';
  return dest;
}
