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
#include <getopt.h>
#include "arraymaker.h"

static void usage() {
  printf("\narraymaker [options] <arguments>\n");
  printf("\nCreate large arrays of randomly sorted numbers to use for learning about algorithm timing.\n");
  printf("\n\t-c - Create file of numbers. Arguments: <file-name> <length of array>\n");
  printf("\t-s - Sort. Arguments: <file> <algorithm>\n");
  printf("\t-h - print out this information.\n\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{

  int opt, len;
  int *outer_array; // variable to hold array returned by load_array()
  char *file_name, *algorithm;

  if (argc < 2) {
    usage();
    return 1;
  }

  while ((opt = getopt(argc, argv, "hc:s:")) != -1) {
    switch(opt) {

      // help: print usage
      case 'h': 
        usage();
        break;

      // create: create file of ints with length based on count
      case 'c':
        if (argc != 4) {
          usage();
        }
        file_name = optarg;
        int count = atoi(argv[3]);

        create_file(file_name, count);
        printf("%s file successfully created\n", file_name);
        exit(0);
        break;

      // sort: sorts file of ints with algorithm used as arg
      case 's':
        if (argc != 4) {
          usage();
        }
        file_name = optarg;
        algorithm = argv[3];
        //bool exists = check_alg(algorithm);
        outer_array = load_array(file_name, &len);
        break;

      // if unknown char is 'c' or 's', show usage for those flags
      case '?':
        if (optopt == 'c') {
          fprintf(stderr, "Option -%c requires two arguments, file and file-size\n", optopt);
        } else if (optopt == 's') {
          fprintf(stderr, "Option -%c requires two arguments, file and algorithm\n", optopt);
        } else {
          fprintf(stderr, "Unknown option character '-%c.\n", optopt);
        }
        return 1;
      default:
        usage();
    }
  }


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
        return 0;
      }
// INSERTION SORT      
      else if (strcmp(algorithm, "insertion") == 0) {  
        printf("Sorting...\n");
        // start timing
        clock_t t;
        t = clock();
        // call algorithm
        insertion_sort(outer_array, len);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        // end timing
        printf("%s sorted %d elements in %f seconds\n", algorithm, len, time_taken);
        free(outer_array);
        return 0;
      }

// wrong sort
      else {
        printf("ERROR: %s is not available as an option. You can add your own to the files\n", algorithm);
        exit(1);
      }
  return 0;
}
