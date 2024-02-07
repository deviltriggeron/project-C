#ifndef S21_GREP_H_
#define S21_GREP_H_
#define str 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
  int sample;        // e
  int ignore;        // i
  int invert;        // v
  int count;         // c
  int match;         // l
  int number;        // n
  int no_filenames;  // s
  int empty;
} flags;

void grep(flags *opt, char *pattern, char *filename, FILE *fp, int count_file);
void flag(int argc, char *argv[], flags *opt, FILE *fp, int count_file);
//void s21_grep_i(char *pattern, char *filename, FILE *fp, int count_file)
#endif
