#include "sstring.h"

void *trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }

  size_t src_len = strlen(src);
  size_t start = 0;
  size_t end = src_len - 1;

  while (start <= end && strchr(trim_chars, src[start]) != NULL) {
    start++;
  }
  while (end > start && strchr(trim_chars, src[end]) != NULL) {
    end--;
  }
  size_t new_len = end - start + 1;
  char *trimmed_str = (char *)malloc((new_len + 1) * sizeof(char));
  if (trimmed_str == NULL) {
    return NULL;
  }
  strncpy(trimmed_str, src + start, new_len);
  trimmed_str[new_len] = '\0';
  return trimmed_str;
}

int main () {
  char s1[30] = "-?hello, world!";
  char s3[100] = "!?-";

  char result[100] = "hello, world";
  char *s2 = trim(s1, s3);
  printf("%s\n%s\n", s2, result);
  free(s2);
  return 1;
}