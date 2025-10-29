#include "cat.h"
void process_line(flags *flg, char *line, int *string_number,
                  int *empty_number);
void outline(flags *flg, char *line);

int argument_parser(int argc, char **argv, flags *flg) {
  int status = 1;
  struct option long_options[] = {
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {"number-nonblank", no_argument, NULL, 'b'},
      {0, 0, 0, 0},
  };

  int opt;
  while ((opt = getopt_long(argc, argv, "bneETtsv", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        flg->b = 1;
        break;
      case 'n':
        flg->n = 1;
        break;
      case 's':
        flg->s = 1;
        break;
      case 'e':
        flg->e = 1;
        flg->v = 1;
        break;
      case 'E':
        flg->e = 1;
        break;
      case 'T':
        flg->t = 1;
        break;
      case 't':
        flg->t = 1;
        flg->v = 1;
        break;
      case 'v':
        flg->v = 1;
        break;
      default:
        status = 0;
        break;
    }
  }
  return status;
}

char v_output(char ch) {
  if (ch < 32 && ch != 9 && ch != 10) {
    ch += 64;
    putchar('^');
  } else if (ch == 127) {
    putchar('^');
    ch = '?';
  }
  return ch;
}

#include "cat.h"

void process_file(const char *filename, flags *flg, int *string_number) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    fprintf(stderr, "No such file: %s\n", filename);
    return;
  }

  char *line = NULL;
  size_t memline = 0;
  int read = 0;
  read = getline(&line, &memline, f);

  int empty_number = 0;
  while (read != -1) {
    process_line(flg, line, string_number, &empty_number);
    read = getline(&line, &memline, f);
  }
  free(line);
  fclose(f);
}

void process_line(flags *flg, char *line, int *string_number,
                  int *empty_number) {
  if (line[0] == '\n') {
    (*empty_number)++;
  } else {
    *empty_number = 0;
  }

  if (flg->s && *empty_number > 1) {
    return;
  }

  if (flg->b && line[0] != '\n') {
    flg->n = 0;
    printf("%6d\t", *string_number);
    (*string_number)++;
  } else if (flg->n) {
    printf("%6d\t", *string_number);
    (*string_number)++;
  }

  outline(flg, line);
}

void outline(flags *flg, char *line) {
  for (int i = 0; line[i] != '\0'; i++) {
    if (flg->e && line[i] == '\n') putchar('$');
    if (flg->v) line[i] = v_output(line[i]);
    if (flg->t && line[i] == '\t') {
      printf("^I");
    } else {
      putchar(line[i]);
    }
  }
}

int main(int argc, char **argv) {
  flags flg = {0};
  int string_number = 1;

  if (argument_parser(argc, argv, &flg) == 1) {
    while (optind < argc) {
      process_file(argv[optind], &flg, &string_number);
      optind++;
    }
  }

  return 0;
}
