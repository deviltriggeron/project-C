#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define str 2096

typedef struct {
  int number_non_blank;  // b
  int ends;              // e
  int number;            // n
  int squeeze;           // s
  int tabs;              // t
  int empty;
} flags;

void flag(int argc, char *argv[], flags *opt, FILE *fp, char *ch);
void func(flags *opt, FILE *fp, char *ch);

#endif
