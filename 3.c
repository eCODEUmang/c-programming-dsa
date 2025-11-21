#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create list
void createList(int n) {
    struct node *newnode, *temp;
    int value;

    head = NULL;
    for(int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    printf("List created successfully.\n");
}

// Traverse list
void traverse() {
    struct node *temp = head;
    printf("List elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at beginning
void insertBeginning(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;
    printf("Inserted at beginning.\n");
}

// Insert at end
void insertEnd(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Inserted at end.\n");
}

// Insert after given INFO
void insertAfter(int search, int value) {
    struct node *temp = head;

    while(temp != NULL && temp->data != search)
        temp = temp->next;

    if(temp == NULL) {
        printf("Node with data %d not found.\n", search);
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Inserted after %d.\n", search);
}

// Delete from beginning
void deleteBeginning() {
    if(head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Deleted from beginning.\n");
}

// Delete from end
void deleteEnd() {
    if(head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct node *temp = head;

    if(temp->next == NULL) {
        head = NULL;
        free(temp);
        printf("Deleted last node.\n");
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    printf("Deleted from end.\n");
}

// Delete given INFO
void deleteByValue(int value) {
    struct node *temp = head;

    while(temp != NULL && temp->data != value)
        temp = temp->next;

    if(temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted value %d.\n", value);
}

int main() {
    int choice, n, value, search;

    while(1) {
        printf("\n----- Linked List Menu -----\n");
        printf("1. Create list\n");
        printf("2. Traverse\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert at any position\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from end\n");
        printf("8. Delete from any position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("How many nodes you want? ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                traverse();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 5:
                printf("Insert after which value? ");
                scanf("%d", &search);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertAfter(search, value);
                break;

            case 6:
                deleteBeginning();
                break;

            case 7:
                deleteEnd();
                break;

            case 8:
                printf("Delete which value? ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}


