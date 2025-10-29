#ifndef S21_CAT_H
#define S21_CAT_H
#define _GNU_SOURCE

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int b, e, n, s, t, v;
} flags;

char v_output(char ch);
void process_file(const char *filename, flags *flg, int *string_number);
void process_line(flags *flg, char *line, int *string_number,
                  int *empty_number);
void outline(flags *flg, char *line);
int argument_parser(int argc, char **argv, flags *flg);

#endif
