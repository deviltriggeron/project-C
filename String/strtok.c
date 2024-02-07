#include "sstring.h"

char *strtok(char *str, const char *delim) {
  static char *token = NULL;
  if (str != NULL) {
    token = str;
  } else if (token == NULL) {
    return NULL;
  }

  char *result = token;

  while (*result && strchr(delim, *result)) {
    result++;
  }

  if (*result == '\0') {
    token = NULL;
    return NULL;
  }

  char *end = result + 1;
  while (*end && !strchr(delim, *end)) {
    end++;
  }

  if (*end) {
    *end = '\0';
    token = end + 1;
  } else {
    token = NULL;
  }

  return result;
}
