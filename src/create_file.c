/*
  Takes a file and an int as an argument
  the file arg is the name of the file to be created
  the int len arg is the length of the file -> i.e. the amount of lines of random numbers

  it then generate random numbers and prints them to the file
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_file(char *file, int len)
{
  int i, number, lower, upper;
  FILE *fp;

  // these variables dictate the range of random numbers
  lower = 0;
  upper = 99999;

  if (len > 9999999) {
    fprintf(stderr, "%d is too big. The number needs to be 9999999 or smaller\n", len);
    exit(EXIT_FAILURE);
  }

  // open file in append mode
  fp = fopen(file, "w");
  if (fp == NULL) {
      fprintf(stderr, "Could not open file %s\n", file);
      exit(EXIT_FAILURE);
  }

  srand(time(0)); // seed for generating random number
  for (i = 0; i < len; i++) {
    // generate random number
    //number = rand() % (upper - lower + 1) + lower;
    number = (rand() % upper) + 1;
    // then write to file
    fprintf(fp, "%d\n", number);
  }
  fclose(fp);
}
