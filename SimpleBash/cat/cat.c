#include "s21_cat.h"

int main(int argc, char *argv[]) {
  char ch[str];
  char a[str];
  FILE *fp;
  flags opt = {0};
  if (argc == 1) {
    while (*a != EOF) {
      fgets(a, str, stdin);
      printf("%s", a);
    }
  } else {
    flag(argc, argv, &opt, fp, ch);
  }
  return 0;
}

void func(flags *opt, FILE *fp, char *ch) {
  int line_number = 1;
  char c = 0;
  char line[str];
  bool squeeze = false;
  opt->empty = 1;
  while (fgets(ch, str, fp) > 0) {
    c = *ch;
    if (opt->squeeze && c == '\n') {  // s
      if (squeeze) continue;
      squeeze = true;
    } else {
      squeeze = false;
    }
    if (opt->number == 1 && opt->number_non_blank == 0) {  // n
      printf("%6d\t", line_number++);
    } else if (opt->number_non_blank) {  // b priority
      if (c != '\n') printf("%6d\t", line_number++);
    }
    if (opt->tabs) {  // t
      for (int i = 0; i < strlen(ch); i++) {
        if (ch[i] == '\t') {
          printf("^");
          ch[i] = '\t' + 64;
        }
      }
    }
    if (opt->ends) {  // e
      for (int i = 0; i < strlen(ch); i++) {
        (ch[i] == '\n') ? printf("$%c", ch[i]) : printf("%c", ch[i]);
      }
    }
    if (opt->ends == 0) printf("%s", ch);
  }
  fclose(fp);
}

void flag(int argc, char *argv[], flags *opt, FILE *fp, char *ch) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      for (int j = 1; argv[i][j] != '\0'; j++) {
        switch (argv[i][j]) {
          case 'b':
            opt->number_non_blank = 1;
            break;
          case 'e':
            opt->ends = 1;
            break;
          case 'n':
            opt->number = 1;
            break;
          case 's':
            opt->squeeze = 1;
            break;
          case 't':
            opt->tabs = 1;
            break;
          default:
            printf(
                "s21_cat: illegal option -- %c\nUsage: ./s21_cat [-benst] "
                "[file ...]\n",
                argv[i][j]);
            exit(1);
            break;
        }
      }
    } else {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {
        printf("%s: No such file or directory\n", argv[i]);
      } else {
        func(opt, fp, ch);
      }
    }
  }
}
