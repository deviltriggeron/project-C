#include "sstring.h"

int strncmp(const char *str1, const char *str2, size_t n) {
  unsigned char char1, char2;
  while (n) {
    char1 = *str1++;
    char2 = *str2++;
    if (char1 != char2) {
      return char1 - char2;
    }
    if (!char1) {
      break;
    }
    n--;
  }
  return 0;
}