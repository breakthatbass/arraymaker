#include <stdio.h>


void bubblesort(int *arr, int n) {
  int i, key_item, j;
  for (i = 0; i < n; i++) {
    key_item = arr[i];

    j = i - 1;

    while (j >= 0 && arr[j] > key_item) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j + 1] = key_item;
  }
}
