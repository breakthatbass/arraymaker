/*
  Takes a file that was created by the create_file() function
  reads it line by line and loads each line into an array
  returns a pointer to the array
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

// load array takes a file, parses it, and load it into an array
// it then calls a function from another file
int *load_array(char *file)
{
  int i, len, file_line_count;
  static int *nums; // array to then transfer to

  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    printf("could not open file %s\n", file);
    exit(1);
  }

  file_line_count = count_lines(file); //get the amount of lines from file
  // allocate memory for the nums array based on the size of the file
  nums = (int*)malloc(file_line_count * sizeof(int));
  // each line comes in as a char so it needs a char array
  char line[file_line_count][100];

  // go through each line in file and append to line array
  i = 0;
  while (fgets(line[i], file_line_count, fp)) {
    line[i][strlen(line[i]) - 1] = '\0';
    i++;
  }

  len = sizeof(line)/sizeof(line[0]);
  // convert each element to int and copy into nums array
  for (i = 0; i < len; ++i) {
        nums[i] = atoi(line[i]);
  }
  fclose(fp);

  return nums;
}
