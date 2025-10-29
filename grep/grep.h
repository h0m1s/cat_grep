#ifndef S21_GREP_H
#define S21_GREP_H
#define _GNU_SOURCE

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int e, i, v, c, l, n, s, h;
  char* pattern;
} flags;
int argument_parser(int argc, char** argv, flags* flg);
void output_line(char* line, int n);
int procces_file(flags* flg, char* path, regex_t* reg);
void output(flags* flg, int argc, char** argv);

#endif