/*
  Takes a file that was created by the create_file() function
  reads it line by line and loads each line into an array
  returns a pointer to the array
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arraymaker.h"

#define MAX_LINE 7

int *load_array(char *file, int *file_length)
{
  int i, file_line_count;
  static int *nums; // array to then transfer to
 

  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    fprintf(stderr, "could not open file %s\n", file);
    exit(EXIT_FAILURE);
  }

  file_line_count = count_lines(file); //get the amount of lines from file
  *file_length = file_line_count;

  // allocate memory for the nums array based on the size of the file
  nums = (int*)malloc(file_line_count * sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Not enough memory. Aborting...\n");
    exit(EXIT_FAILURE);
  }

  // each line comes in as a char so it needs a char array
  char line[MAX_LINE];

  // go through each line in file and append to line array
  i = 0;
  while (fgets(line, MAX_LINE, fp)) {
      // convert to int and append to nums array
      nums[i] = atoi(line);
      i++;
  }
  fclose(fp);
  
  return nums;
}
