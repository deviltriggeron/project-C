#ifndef SSTRING_PLUS
#define SSTRING_PLUS
#define _GNU_SOURSE_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NULL ((void *)0)

typedef long unsigned int size_t;

void *memchr(const void *str, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *str, int c, size_t n);
void *to_upper(const char *str);
void *to_lower(const char *str);
void *insert(const char *src, const char *str, size_t start_index);
void *trim(const char *src, const char *trim_chars);
void *strcpy(char *dest, char *src);

char *strtok(char *str, const char *delim);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strchr(const char *str, int c);
char *strncat(char *dest, const char *src, size_t n);
char *strncpy(char *dest, const char *src, size_t n);
char *strerror(int errnum);
char *strcat(char *dest, const char *src);

int memcmp(const void *str1, const void *str2, size_t n);
int strncmp(const char *str1, const char *str2, size_t n);

size_t strlen(const char *str);
size_t strcspn(const char *str1, const char *str2);

int sprintf(char *dest, char *format, ...);

struct Specifier {
  int g;
  int f;
  int x;
  int c;
  int h;
  int u;
  int string;
  int plus;
  int minus;
  int dot_f;
  int zeroes_to_cut;
  int custom_precision;
  int digit_len;
  int digit_sign;
  int flag_space;
  int spaces;
  int flag_trail;
  int l;
};

#endif