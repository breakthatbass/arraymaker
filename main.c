/*

  This file is the entry point to the program.

  This program is meant to use alongside with algorithms as a way
  to easily create and use large arrays to test timing
  of algorithms.

  It is meant to use alongside the UNIX time command.

  It's a bit hard to get a sense of the timing of different sorting
  and searching algorithms without very large arrays so it doesn't seem so
  instantaneous.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[])
{

  int c, i, len, file_line_count;
  int *outer_array; // variable to hold array returned by load_array()


  if (argc < 2) {
    printf("usage: arraymaker command subcommand(s)\n\n");
    return 1;
  }

  char *command = argv[1];

  if (strcmp(command, "help") == 0) {
    printf("\ncommands:\n\ncreate arraylength file.txt\nload file.txt algorithmfile.c\n");
    printf("\nnote: the algorithm file must accept arguments and must be the entry point to the algorithm(s) if they are in external files\n\n");
  }

  // create command
  if (strcmp(command, "create") == 0 && argc == 4) {
    char *file_out = argv[3];
    int length = atoi(argv[2]);
    create_file(file_out, length);
    exit(0);
  }

  // load array command
  if (strcmp(command, "load") == 0 && argc == 3) { // set to 4 after testing
    char *infile = argv[2];
    outer_array = load_array(infile);

    for (i = 0; i < 20; ++i) {
         printf("main func: %d\n", *(outer_array + i));
    }
    exit(0);
  }

  return 0;
}
