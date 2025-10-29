#include "grep.h"

int argument_parser(int argc, char** argv, flags* flg) {
  int status = 1;
  int opt;
  while ((opt = getopt_long(argc, argv, "eivclnsh", 0, 0)) != -1) {
    switch (opt) {
      case 'e':
        flg->e = 1;
        flg->pattern = optarg;
        break;
      case 'i':
        flg->i = REG_ICASE;
        break;
      case 'v':
        flg->v = 1;
        break;
      case 'c':
        flg->c = 1;
        break;
      case 'l':
        flg->l = 1;
        break;
      case 'n':
        flg->n = 1;
        break;
      case 's':
        flg->s = 1;
        break;
      case 'h':
        flg->h = 1;
        break;

      default:
        status = 0;
        break;
    }
  }
  if (flg->pattern == NULL) flg->pattern = argv[optind++];
  if (argc - optind == 1) flg->h = 1;
  return status;
}

void output_line(char* line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
}

int procces_file(flags* flg, char* path, regex_t* reg) {
  FILE* f = fopen(path, "r");
  if (f == NULL) {
    if (flg->s == 0) {
      fprintf(stderr, "grep: %s: ", path);
      perror("");
    }
    return 0;
  }
  char* line = NULL;
  size_t memlen = 0;
  int read = 0;
  int strings_count = 1;
  int same_current = 0;

  read = getline(&line, &memlen, f);
  while (read != -1) {
    int result = regexec(reg, line, 0, NULL, 0);
    if ((result == 0 && !flg->v) || (flg->v && result != 0)) {
      if (!flg->c && !flg->l) {
        if (!flg->h) printf("%s:", path);
        if (flg->n) printf("%d:", strings_count);
        output_line(line, read);
      }
      same_current++;
    }
    read = getline(&line, &memlen, f);
    strings_count++;
  }
  if (flg->c && !flg->l) {
    if (!flg->h) printf("%s:", path);
    printf("%d\n", same_current);
  }
  if (flg->l && strings_count > 0) printf("%s\n", path);
  free(line);
  fclose(f);
  return 1;
}

void output(flags* flg, int argc, char** argv) {
  regex_t re;
  int error = regcomp(&re, flg->pattern, flg->i);
  if (error) perror("Error");  //
  for (int i = optind; i < argc; i++) {
    procces_file(flg, argv[i], &re);
  }
  regfree(&re);
}

int main(int argc, char** argv) {
  flags flg = {0};
  argument_parser(argc, argv, &flg);
  if (flg.pattern == NULL) {
    return 0;
  }
  output(&flg, argc, argv);
  return 0;
}