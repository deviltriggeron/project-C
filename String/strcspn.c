#include "sstring.h"

size_t strcspn(const char *str1, const char *str2) {
  size_t res = 0;
  size_t j = 0;
  while (str1[j] != '\0') {
    size_t i = 0;
    while (str2[i] != '\0') {
      if (str1[j] == str2[i]) {
        return res;
      }
      i++;
    }
    res++;
    j++;
  }
  return res;
}