/***

  This file is the entry point to the program.

  This program is meant to use alongside with algorithms as a way
  to easily create and use large arrays to test timing
  of algorithms.

  It is meant to use alongside the UNIX time command.

  It's a bit hard to get a sense of the timing of different sorting
  and searching algorithms without very large arrays so it doesn't seem so
  instantaneous.

***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arraymaker.h"

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
    printf("\ncommands:\n\ncreate arraylength file.txt\nsort file.txt algorithmfile.c\n");
  }

  // create command
  if (strcmp(command, "create") == 0 && argc == 4) {
    char *file_out = argv[3];
    int length = atoi(argv[2]);
    create_file(file_out, length);
    return 0;
  }

// SORTING
  else if (strcmp(command, "sort") == 0 && argc == 4) { // set to 4 after testing
    char *infile = argv[2];
    outer_array = load_array(infile, &len);
    char *algorithm = argv[3];

// SHELLSORT
      if (strcmp(algorithm, "shellsort") == 0) {
        shellsort(outer_array, len);
        //return 0;
      }
// BUBBLESORT
      else if (strcmp(algorithm, "bubblesort") == 0) {  
        bubblesort(outer_array, len);
        //return 0;
      }
// QUICKSORT
      else if (strcmp(algorithm, "quicksort") == 0) {
        // qsort() comes from the C standard library and will
        // be better than any version I could write
        qsort(outer_array, len, sizeof(int), cmpfunc);
        //return 0;
      }
// GNOMESORT      
      else if (strcmp(algorithm, "gnomesort") == 0) {  
        gnome_sort(outer_array, len);
        //return 0;
      }
// wrong sort
      else {
        printf("ERROR: %s is not available as an option. You can add your own to the files\n", algorithm);
        return 2;
      }

  }
  else {
    printf("Usage: arraymaker\n");
    printf("\t\tcreate num-of-elements file.txt\n");
    printf("\t\tsort file.txt algorithm\n");
    return 3;
  }
  for (i = 0; i < len; ++i) {
    printf("%d: %d\n", i+1, *(outer_array + i));
  } 
  
  return 0;
}
