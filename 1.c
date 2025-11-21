#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create list */
void createList() {
    int n, val;
    struct Node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data of node %d: ", i + 1);
        scanf("%d", &val);

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    printf("List created successfully.\n");
}

/* Traverse */
void traverse() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Insert at beginning */
void insertBeginning() {
    int val;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value to insert: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = head;
    head = newnode;

    printf("Inserted at beginning.\n");
}

/* Insert at end */
void insertEnd() {
    int val;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    printf("Enter value to insert: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Inserted at end.\n");
}

/* Insert after given info */
void insertAfter() {
    int key, val;
    struct Node *temp = head;

    printf("Enter the node value after which to insert: ");
    scanf("%d", &key);

    printf("Enter new node value: ");
    scanf("%d", &val);

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted after %d.\n", key);
}

/* Delete from beginning */
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    printf("Deleted from beginning.\n");
}

/* Delete from end */
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        printf("Last node deleted.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Deleted from end.\n");
}

/* Delete given node */
void deleteGiven() {
    int key;
    printf("Enter value of node to delete: ");
    scanf("%d", &key);

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node %d deleted.\n", key);
}

/* Main menu */
int main() {
    int choice;

    while (1) {
        printf("\n-------- MENU --------\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert After Given Node\n");
        printf("6. Delete From Beginning\n");
        printf("7. Delete From End\n");
        printf("8. Delete Given Node\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: traverse(); break;
            case 3: insertBeginning(); break;
            case 4: insertEnd(); break;
            case 5: insertAfter(); break;
            case 6: deleteBeginning(); break;
            case 7: deleteEnd(); break;
            case 8: deleteGiven(); break;
            case 9: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}


