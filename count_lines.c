/*

  This function takes a file as an argument
  and returns the number of lines in file

*/

#include <stdio.h>

int count_lines(char *file)
{
  FILE *fp;
  int count = 0;  // Line counter (result)
  char c;  // To store a character read from file

  // Open the file
    fp = fopen(file, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", file);
        return 1;
    }

    // Extract characters from file and store in character c
   for (c = getc(fp); c != EOF; c = getc(fp))
       if (c == '\n') // Increment count if this character is newline
           count = count + 1;

   // Close the file
   fclose(fp);
   return count;
}
