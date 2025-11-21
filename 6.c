#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initList(List* lst) {
    lst->head = NULL;
}

void appendNode(List* lst, int value) {
    Node* newNode = createNode(value);
    if (!lst->head) {
        lst->head = newNode;
        return;
    }
    Node* temp = lst->head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void printList(List* lst) {
    Node* temp = lst->head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* mergeSortedLists(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* result = NULL;

    if (h1->data <= h2->data) {
        result = h1;
        result->next = mergeSortedLists(h1->next, h2);
    } else {
        result = h2;
        result->next = mergeSortedLists(h1, h2->next);
    }

    return result;
}

void concatenateSortedLists(List* A, List* B, List* R) {
    R->head = mergeSortedLists(A->head, B->head);
}

void clearList(List* lst) {
    Node* temp = lst->head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    lst->head = NULL;
}

void inputList(List* lst, int count) {
    for (int i = 0; i < count; i++) {
        int x;
        scanf("%d", &x);
        appendNode(lst, x);
    }
}

void displayMenu() {
    printf("\n----- Linked List Menu -----\n");
    printf("1. Create first sorted list\n");
    printf("2. Create second sorted list\n");
    printf("3. Concatenate (merge) lists\n");
    printf("4. Traverse all lists\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void displayAllLists(List* A, List* B, List* R) {
    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);
    printf("Merged List: ");
    printList(R);
}

int main() {
    List A, B, R;
    initList(&A);
    initList(&B);
    initList(&R);

    int choice, n;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearList(&A);
                printf("How many nodes for List A? ");
                scanf("%d", &n);
                printf("Enter %d sorted elements:\n", n);
                inputList(&A, n);
                break;

            case 2:
                clearList(&B);
                printf("How many nodes for List B? ");
                scanf("%d", &n);
                printf("Enter %d sorted elements:\n", n);
                inputList(&B, n);
                break;

            case 3:
                clearList(&R);
                printf("Concatenating lists...\n");
                concatenateSortedLists(&A, &B, &R);
                printf("Merged successfully.\n");
                break;

            case 4:
                displayAllLists(&A, &B, &R);
                break;

            case 5:
                clearList(&A);
                clearList(&B);
                clearList(&R);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

