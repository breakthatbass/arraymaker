void create_file(char *file, int len);
int count_lines(char *file);
int *load_array(char *file, int *file_length);

// algorithms
void shellsort(int *v, int n);
void bubblesort(int *arr, int n);
void gnome_sort(int *arr, int len);

// helpers
int cmpfunc (const void * a, const void * b);
void swap(int *x, int *y);

