#include "../src/arraymaker.h"

void insertion_sort(int *array, int n)
{
  int i, key_item, j;
  for (i = 0; i < n; i++) {
    key_item = array[i];

    j = i - 1;

    while (j >= 0 && array[j] > key_item) {
      array[j+1] = array[j];
      j--;
    }
    array[j + 1] = key_item;
  }
}
