#include "sstring.h"

void *insert(const char *src, const char *str, size_t start_index) {
  int src_length = strlen(src);
  int str_length = strlen(str);
  int result_length = src_length + str_length;
  int size = start_index;
  if (src == NULL || str == NULL || size > src_length + str_length ||
      src_length == 0 || size < 0) {
    return NULL;
  }

  char *result = (char *)malloc((result_length) * sizeof(char));

  strncpy(result, src, start_index);
  result[start_index] = '\0';

  strcat(result, str);

  strcat(result, src + start_index);

  return result;
}
