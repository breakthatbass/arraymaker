#include <stdio.h>
#include "../src/arraymaker.h"

void gnome_sort(int *arr, int len)
{
    int pos = 0;
    while (pos < len) {
        if (pos == 0 || arr[pos] >= arr[pos - 1]) {
            pos++;
        }
        else {
            swap(&arr[pos], &arr[pos - 1]);
            pos--;
        }
    }

}
