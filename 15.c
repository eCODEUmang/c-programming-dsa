#include <stdio.h>
#include <stdlib.h>

/* Merge two sorted halves: arr[l..m] and arr[m+1..r] */
static void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (!L || !R) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    /* Merge temp arrays back into arr */
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    /* Copy remaining elements */
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

/* Merge sort recursive */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* Read n elements into array */
int *readArray(size_t n) {
    if (n == 0) return NULL;
    int *a = malloc(n * sizeof(int));
    if (!a) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "Invalid input at element %zu\n", i + 1);
            free(a);
            exit(EXIT_FAILURE);
        }
    }
    return a;
}

/* Print elements */
void printArray(const int arr[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i + 1 < n) putchar(' ');
    }
    putchar('\n');
}

int main(void) {
    size_t n;
    if (scanf("%zu", &n) != 1) {
        fprintf(stderr, "Failed to read number of elements\n");
        return 1;
    }

    int *arr = readArray(n);

    if (n > 0)
        mergeSort(arr, 0, (int)n - 1);

    printArray(arr, n);

    free(arr);
    return 0;
}
