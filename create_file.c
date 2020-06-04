#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void create_file(char *file, int len)
{
  // when loop ends close file
  int i, number, lower, upper;
  char num_str;
  FILE *fp;

  // these variables dictate the range of random numbers
  lower = 0;
  upper = 999999;

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
