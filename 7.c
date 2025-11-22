#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void concatenate(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        *head2 = NULL;
        return;
    }
    if (*head2 == NULL) {
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head2;
    (*head2)->prev = temp;
    *head2 = NULL;
}

void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, data, n, i;

    while (1) {
        printf("\n----- List Menu -----\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Concatenate List 1 and List 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes for List 1: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertEnd(&list1, data);
                }
                break;

            case 2:
                printf("Enter number of nodes for List 2: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insertEnd(&list2, data);
                }
                break;

            case 3:
                printf("List 1: ");
                displayList(list1);
                break;

            case 4:
                printf("List 2: ");
                displayList(list2);
                break;

            case 5:
                printf("Concatenating List 2 into List 1...\n");
                concatenate(&list1, &list2);
                printf("Concatenation complete.\n");
                break;

            case 6:
                freeList(&list1);
                freeList(&list2);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

