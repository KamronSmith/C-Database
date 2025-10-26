#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *argv[]) {
  printf("Usage: %s -n -f <database file>\n", argv[0]);
  printf("\t -n  - create new database file\n");
  printf("\t -f  - (required) path to database file");
}

int main(int argc, char *argv[]) { 
  int c;
  bool newfile = false;
  char *filepath = NULL;

  int database_file_descriptor = -1;

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

  if (filepath == NULL) {
    printf("Filepath is a required argument\n");
    print_usage(argv);

    return 0;
  }

  if (newfile) {
    database_file_descriptor = create_db_file(filepath);
    if (database_file_descriptor == STATUS_ERROR) {
      printf("Unable to create database file\n");
      return -1;
    }
  } else {
    database_file_descriptor = open_db_file(filepath);
    if (database_file_descriptor == STATUS_ERROR) {
      printf("Unable to open database file");
      return -1;
    }
  }
}
