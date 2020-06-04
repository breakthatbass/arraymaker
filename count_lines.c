/*
  Takes a file as an argument
  and returns the number of lines in file

  essentially this function is just malloc() for a file length size
  ...only because i couldn't get the program to compile using malloc()
*/

#include <stdio.h>

int count_lines(char *file)
{
  FILE *fp;
  int count = 0;  // Line counter (result)
  char c;  // To store a character read from file

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Could not open file in count lines %s\n", file);
        return 1;
    }

    // Extract characters from file and store in character c
   for (c = getc(fp); c != EOF; c = getc(fp))
       if (c == '\n') { // Increment count if this character is newline
           count++;
       }

   fclose(fp);
   return count;
}
