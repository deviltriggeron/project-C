#include "s21_grep.h"

void flag(int argc, char *argv[], flags *opt, FILE *fp, int count_file) {
  char *pattern = NULL, *filename = NULL;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      for (int j = 1; argv[i][j] != '\0'; j++) {
        switch (argv[i][j]) {
          case 'e':
            opt->sample = 1;
            break;
          case 'i':
            opt->ignore = 1;
            opt->empty = 0;
            break;
          case 'v':
            opt->invert = 1;
            opt->empty = 0;
            break;
          case 'c':
            opt->count = 1;
            opt->empty = 0;
            break;
          case 'l':
            opt->match = 1;
            opt->count = 1;
            opt->empty = 0;
            break;
          case 'n':
            opt->number = 1;
            break;
          case 's':
            opt->no_filenames = 1;
            break;
          default:
            if (opt->no_filenames == 0)
              printf("s21_grep: invalid option -- %c", argv[i][j]);
            exit(1);
            break;
        }
      }
    } else {
      if (pattern == NULL) {
        pattern = argv[i];
      } else if (pattern != NULL) {
        filename = argv[i];
        count_file++;
        grep(opt, pattern, filename, fp, count_file);
      }
    }
  }
}

void grep(flags *opt, char *pattern, char *filename, FILE *fp, int count_file) {
  int count = 0;
  int line_number = 0;
  char *line = NULL;
  char *template = NULL;
  size_t len = 0;
  if ((fp = fopen(filename, "r")) == NULL) {
    if (opt->no_filenames == 0)
      printf("%s: No such file or directory\n", filename);
  } else {
    while ((getline(&line, &len, fp) != -1)) {
      if (opt->number && opt->count == 0 && opt->ignore == 0) {
        line_number++;
        if ((opt->invert == 0) && (strstr(line, pattern)))
          printf("%d:", line_number);
        if ((opt->invert) && (!strstr(line, pattern)))
          printf("%d:", line_number);
      }
      if (opt->count && opt->invert == 0)
        if (strstr(line, pattern)) count++;
      if (opt->invert) {
        if (!strstr(line, pattern)) {
          count++;
          if (opt->count == 0)
            (count_file > 1) ? printf("%s:%s", filename, line)
                             : printf("%s", line);
        }
      }
      if (opt->ignore && opt->count == 0) {
        if (strcasestr(line, pattern) != NULL)
          (count_file > 1) ? printf("%s:%s", filename, line)
                           : printf("%s", line);
      } else if (opt->empty || opt->sample) {  // standart grep
        if (strstr(line, pattern))
          (count_file > 1) ? printf("%s:%s", filename, line)
                           : printf("%s", line);
      }
    }
    if (opt->count && opt->match == 0)
      (count_file > 1) ? printf("%s:%d\n", filename, count)
                       : printf("%d\n", count);
    if (opt->match)  // l
      if (count != 0) printf("%s\n", filename);
    fclose(fp);
    free(line);
  }
}

// void s21_grep_i(char *pattern, char *filename, FILE *fp, int count_file) {
//     int count = 0;
//     int line_number = 0;
//     char *line = NULL;
//     char *template = NULL;
//     while ((getline(&line, &len, fp) != -1)) {
//       if (strcasestr(line, pattern) != NULL)
//         (count_file > 1) ? printf("%s:%s", filename, line) : printf("%s", line);
//     }
// }

// void s21_grep_v(char *pattern, char *filename, FILE *fp, int count_file) {
//     int count = 0;
//     int line_number = 0;
//     char *line = NULL;
//     char *template = NULL;
// }

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  int count_file = 0;
  flags opt = {0};
  opt.empty = 1;
  if (argc > 2)
    flag(argc, argv, &opt, fp, count_file);
  else
    while (1) getchar();
  fflush(stdin);
  return 0;
}
