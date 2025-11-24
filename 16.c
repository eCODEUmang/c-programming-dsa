#include <stdio.h>
#include <stdlib.h>

void createArray(int **arr, int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);

    *arr = (int *)malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &((*arr)[i]));
    }

    printf("Array created successfully.\n");
}

void traverseArray(int *arr, int n) {
    printf("Traversing Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int *arr = NULL;
    int n = 0, choice, key, pos;

    while (1) {
        printf("\n===== LINEAR SEARCH MENU =====\n");
        printf("1. Create Array\n");
        printf("2. Traverse Array\n");
        printf("3. Search Element (Linear Search)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createArray(&arr, &n);
            break;

        case 2:
            if (arr == NULL) {
                printf("Array not created yet.\n");
            } else {
                traverseArray(arr, n);
            }
            break;

        case 3:
            if (arr == NULL) {
                printf("Create the array first.\n");
            } else {
                printf("Enter element to search: ");
                scanf("%d", &key);
                pos = linearSearch(arr, n, key);
                if (pos == -1)
                    printf("Element %d not found in the array.\n", key);
                else
                    printf("Element %d found at position %d.\n", key, pos + 1);
            }
            break;

        case 4:
            printf("Exiting program.\n");
            free(arr);
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

