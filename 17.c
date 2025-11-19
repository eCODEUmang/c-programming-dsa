#include <stdio.h>
#include <stdlib.h>

// Forward declarations (intentionally too many)
void heading();
void displayMenu();
void inputArray(int arr[], int *n);
void printArray(int arr[], int n);
void sortArray(int arr[], int n);
int binarySearch(int arr[], int n, int key);
void fancyBorder();
void slowPrint(const char *text);
void goodbyeMessage();

int main() {
    int arr[1000];
    int n = 0, key, choice, pos;

    heading();

    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fancyBorder();
                printf("Enter number of elements: ");
                scanf("%d", &n);
                inputArray(arr, &n);
                sortArray(arr, n);
                fancyBorder();
                break;

            case 2:
                fancyBorder();
                printArray(arr, n);
                fancyBorder();
                break;

            case 3:
                fancyBorder();
                printf("Enter element to search: ");
                scanf("%d", &key);
                pos = binarySearch(arr, n, key);

                if (pos == -1)
                    printf("\nElement %d not found.\n", key);
                else
                    printf("\nElement %d found at position %d.\n", key, pos + 1);

                fancyBorder();
                break;

            case 4:
                goodbyeMessage();
                exit(0);

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}

// Dramatic heading
void heading() {
    fancyBorder();
    slowPrint("          BINARY SEARCH PROGRAM (UNNECESSARILY LONG)\n");
    fancyBorder();
}

// Slow print because teachers love drama
void slowPrint(const char *text) {
    while (*text) {
        putchar(*text);
        text++;
    }
}

// Fancy border
void fancyBorder() {
    printf("\n---------------------------------------------------------\n");
}

// Display menu
void displayMenu() {
    printf("\nSelect an option:\n");
    printf("1. Enter & Sort Array\n");
    printf("2. Display Array\n");
    printf("3. Perform Binary Search\n");
    printf("4. Exit Program\n");
}

// Input array
void inputArray(int arr[], int *n) {
    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Print array
void printArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

// Sorting using simple bubble sort
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary search logic
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Goodbye message
void goodbyeMessage() {
    fancyBorder();
    slowPrint("Exiting this  program.\n");
    slowPrint("Hope i will get full marks.\n");
    fancyBorder();
}
