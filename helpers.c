/*** 
 * some of the algorithms are dependent on other functions to run. 
 * this file stores these function
 *  ***/

// for use with qsort()
int cmpfunc (const void * a, const void * b) 
{
  return ( *(int*)a - *(int*)b );
}

// for use with gnome_sort()
void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}