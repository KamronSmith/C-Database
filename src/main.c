#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *nargv[]) {

}

int main(int argc, char *argv[]) { 
  int c;
  bool newfile = false;
  char *filepath = NULL;

  while ((c = getopt(argc, argv, "nf:")) != -1) {
    switch (c) {
    case 'n':
      newfile = true;
      break;

    case 'f':
      filepath = optarg;
      break;

    case '?':
      printf("Unknown option -%c\n", c);
      break;

    default:
      return -1;
    }
  }

  printf("Newfile: %d\n", newfile);
  printf("Filepath: %s", filepath);
}
