/*
  Takes a file as an argument
  and returns the number of lines in file
*/
#include <stdio.h>
#include <stdlib.h>

int count_lines(char *file)
{
  FILE *fp;
  int count = 0;  // Line counter
  char c;  // To store the character read from file

  fp = fopen(file, "r");
  if (fp == NULL) {
      fprintf(stderr, "Could not open file %s\n", file);
      exit(EXIT_FAILURE);
  }

  // Extract characters from file and store in char c
  while ((c = getc(fp)) && c != EOF) {
    if (c == '\n') { 
      count++;
    }
  }

  fclose(fp);
  return count;
}
