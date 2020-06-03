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
  int nums[101]; // array to transfer ints into after collecting


  if (argc != 2) {
    printf("usage: arraymaker file.ext\n");
    return 1;
  }

  char *infile = argv[1];
  FILE *fp = fopen(infile, "r");

  file_line_count = count_lines(infile);

  // each line comes in as a char so it needs a char array
  // also, it needs memory allocated for both the length of the array
  // but also the length of each element which is what the 100 is.
  char line[file_line_count][100];

  // make sure the file exists or can be opened
  if (fp == NULL) {
    printf("could not open file %s\n", infile);
    return 2;
  }

  // go through each line in file and append to line array
  i = 0;
  while (fgets(line[i], 101, fp)) {
    line[i][strlen(line[i]) - 1] = '\0';
    i++;
  }

  len = sizeof(line)/sizeof(line[0]);

  for(i = 0; i < len; ++i)
    {
        nums[i] = atoi(line[i]); // convert each element to int
    }

    // print from the nums array
    for(i = 0; i < len; ++i)
      {
          printf(" %d\n", nums[i]);
      }

  fclose(fp);

  return 0;
}
