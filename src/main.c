/***
 * This is the entry point to the program
 * 
 * Arraymaker is used to create very large arrays of random numbers
 * that are randomly sorted for the purpose of using them to learn
 * about timing with sorting algorithms
 * 
 * The bigger the arrays to sort are, the more noticable
 * the time differences can be.
 * 
 * Created by Taylor Gamache in June 2020
 ***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
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
    printf("\ncommands:\ncreate file array-length\nsort file algorithm\n");
  }

  // create command
  if (strcmp(command, "create") == 0 && argc == 4) {
    char *file_out = argv[2];
    int length = atoi(argv[3]);

    // check for correct oderder of arguments
    if (length == 0) { // atoi returns 0 if the string isn't a string of numbers
      printf("Unable to create file\n");
      printf("\ncommands:\ncreate file array-length\nsort file algorithm\n");
      return 2;
    }
    create_file(file_out, length);
    printf("%s file successfully created\n", file_out);
    return 0;
  }

// SORTING
  else if (strcmp(command, "sort") == 0 && argc == 4) { // set to 4 after testing
    char *infile = argv[2];
    outer_array = load_array(infile, &len);
    char *algorithm = argv[3];

// SHELLSORT
      if (strcmp(algorithm, "shellsort") == 0) {
        printf("Sorting...\n");
         // start timing
        clock_t t;
        t = clock();
        // call algorithm
        shellsort(outer_array, len);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        // end timing
        printf("%s sorted %d elements in %f seconds\n", algorithm, len, time_taken);
        free(outer_array);
        return 0;
      }

// BUBBLESORT
      else if (strcmp(algorithm, "bubblesort") == 0) {  
        printf("Sorting...\n");
        // start timing
        clock_t t;
        t = clock();
        // call algorithm
        bubblesort(outer_array, len);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        // end timing
        printf("%s sorted %d elements in %f seconds\n", algorithm, len, time_taken);
        free(outer_array);
        return 0;
      }

// QUICKSORT
      else if (strcmp(algorithm, "quicksort") == 0) {
        printf("Sorting...\n");
        // start timing
        clock_t t;
        // call algorithm
        t = clock();
        // qsort() comes from the C standard library and will
        // be better than any version I could write
        qsort(outer_array, len, sizeof(int), cmpfunc);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        // end timing
        printf("%s sorted %d elements in %f seconds\n", algorithm, len, time_taken);
        free(outer_array);
        return 0;
      }
// GNOMESORT      
      else if (strcmp(algorithm, "gnomesort") == 0) {  
        printf("Sorting...\n");
        // start timing
        clock_t t;
        t = clock();
        // call algorithm
        gnome_sort(outer_array, len);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        // end timing
        printf("%s sorted %d elements in %f seconds\n", algorithm, len, time_taken);
        free(outer_array);
        //return 0;
      }

// wrong sort
      else {
        printf("ERROR: %s is not available as an option. You can add your own to the files\n", algorithm);
        return 3;
      }
  }

  else {
    printf("Usage: arraymaker\n");
    printf("\t\tcreate num-of-elements file.txt\n");
    printf("\t\tsort file.txt algorithm\n");
    return 3;
  }
  // no printing for now
  /*
  for (i = 0; i < len; ++i) {
    printf("%d: %d\n", i+1, *(outer_array + i));
  } 
  */
  return 0;
}
