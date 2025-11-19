#include <stdio.h>
#include <stdlib.h>

/* Swap two integers */
static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Lomuto partition: pivot = arr[high] */
static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* Quick sort recursive */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Read n integers into dynamically allocated array */
int *readArray(size_t n) {
    if (n == 0) return NULL;
    int *a = malloc(n * sizeof(int));
    if (!a) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "Invalid input at element %zu\n", i+1);
            free(a);
            exit(EXIT_FAILURE);
        }
    }
    return a;
}

/* Print array */
void printArray(const int arr[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i + 1 < n) putchar(' ');
    }
    putchar('\n');
}

/* Main: read, sort, print */
int main(void) {
    size_t n;
    if (scanf("%zu", &n) != 1) {
        fprintf(stderr, "Failed to read number of elements\n");
        return 1;
    }

    int *arr = readArray(n);

    if (n > 0) quickSort(arr, 0, (int)n - 1);

    printArray(arr, n);

    free(arr);
    return 0;
}
