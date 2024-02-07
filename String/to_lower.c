#include "sstring.h"

void *to_lower(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  size_t len = strlen(str);
  char *new_str = (char *)malloc((len + 1) * sizeof(char));
  memcpy(new_str, str, len + 1);

  char *ptr = new_str;
  while (*ptr != '\0') {
    if (*ptr >= 'A' && *ptr <= 'Z') {
      *ptr += 32;
    }
    ptr++;
  }
  return new_str;
}
