/*
  Takes a file  and an int as an argument
  the file arg is the name of the file to be created
  the len arg is the length of the file -> i.e. the amount of lines of random numbers

  it then generate random numbers and prints them to the file
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_file(char *file, int len)
{
  int i, number, lower, upper;
  char num_str;
  FILE *fp;

  // these variables dictate the range of random numbers
  lower = 0;
  upper = 99999;

  // open file in append mode
  fp = fopen(file, "w");
  if (fp == NULL) {
      printf("Could not open file %s\n", file);
  }

  srand(time(0)); // seed for generating random number
  for (i = 0; i < len; i++) {
    // generate random number
    number = rand() % (upper - lower + 1) + lower;
    // then write to file
    fprintf(fp, "%d\n", number);
  }
  fclose(fp);
}
