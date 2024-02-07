#include "sstring.h"

char *strrchr(const char *str, int c) {
  const char *last_occurrence = NULL;
  while (*str != '\0') {
    if (*str == c) {
      last_occurrence = str;
    }
    str++;
  }
  if (*str == c) {
    last_occurrence = str;
  }
  return (char *)last_occurrence;
}
