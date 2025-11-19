#include <stdio.h>
#include <stdlib.h>

// Function prototypes (unnecessarily many, just to make it LONG)
void displayMenu();
void takeInput(int arr[], int *n);
void printArray(int arr[], int n);
int linearSearch(int arr[], int n, int key);
void fancyBorder();
void slowPrint(const char *text);
void heading();
void goodbyeMessage();
void clearInputBuffer();

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
                takeInput(arr, &n);
                fancyBorder();
                break;
                
            case 2:
                fancyBorder();
                printArray(arr, n);
                fancyBorder();
                break;
                
            case 3:
                fancyBorder();
                printf("Enter the element to search: ");
                scanf("%d", &key);
                pos = linearSearch(arr, n, key);
                
                if (pos == -1) {
                    printf("\nElement %d not found in the list.\n", key);
                } else {
                    printf("\nElement %d found at position %d.\n", key, pos + 1);
                }
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

// Function that prints the heading
void heading() {
    fancyBorder();
    slowPrint("        LINEAR SEARCH PROGRAM (OVERLY LONG VERSION)\n");
    fancyBorder();
}

// Simple slow print for useless dramatic effect
void slowPrint(const char *text) {
    while (*text) {
        printf("%c", *text);
        text++;
    }
}

// Fancy border for aesthetic reasons only
void fancyBorder() {
    printf("\n--------------------------------------------------------------\n");
}

// Display menu function
void displayMenu() {
    printf("\nChoose an operation:\n");
    printf("1. Enter Array Elements\n");
    printf("2. Display Array\n");
    printf("3. Perform Linear Search\n");
    printf("4. Exit Program\n");
}

// Function to take array input
void takeInput(int arr[], int *n) {
    int i;
    printf("Enter %d elements:\n", *n);
    for (i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Print the array elements
void printArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

// Linear search implementation
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Useless goodbye message but teachers love it
void goodbyeMessage() {
    fancyBorder();
    slowPrint("Thank you for using this unnecessarily long program.\n");
    slowPrint("Good luck for your practical marks.\n");
    fancyBorder();
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
