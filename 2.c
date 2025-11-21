#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create Circular Linked List */
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

        if (head == NULL) {
            head = newnode;
            head->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
    }
    printf("Circular list created successfully.\n");
}

/* Traverse Forward */
void traverseForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Traverse Backward (using reverse scanning trick) */
void traverseBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Backward: ");

    int arr[500], i = 0;
    do {
        arr[i++] = temp->data;
        temp = temp->next;
    } while (temp != head);

    for (int j = i - 1; j >= 0; j--)
        printf("%d ", arr[j]);
    printf("\n");
}

/* Insert at Beginning */
void insertBeginning() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newnode->next = head;
        head = newnode;
        temp->next = head;
    }

    printf("Inserted at beginning.\n");
}

/* Insert at End */
void insertEnd() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Inserted at end.\n");
}

/* Insert After Given Node */
void insertAfter() {
    int key, val;
    printf("Enter the node after which to insert: ");
    scanf("%d", &key);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == key) {
            struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->data = val;
            newnode->next = temp->next;
            temp->next = newnode;
            printf("Inserted after %d.\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node not found.\n");
}

/* Delete From Beginning */
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted from beginning.\n");
        return;
    }

    struct Node *temp = head, *last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);

    printf("Deleted from beginning.\n");
}

/* Delete From End */
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (temp->next == head) {
        head = NULL;
        free(temp);
        printf("Deleted from end.\n");
        return;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    printf("Deleted from end.\n");
}

/* Delete Given Node */
void deleteGiven() {
    int key;
    printf("Enter the node value to delete: ");
    scanf("%d", &key);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    do {
        if (temp->data == key) {
            if (temp == head) {
                deleteBeginning();
                return;
            }

            prev->next = temp->next;
            free(temp);
            printf("Node %d deleted.\n", key);
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    printf("Node not found.\n");
}

/* MAIN MENU */
int main() {
    int choice;

    while (1) {
        printf("\n-------- MENU --------\n");
        printf("1. Create List\n");
        printf("2. Traverse Forward\n");
        printf("3. Traverse Backward\n");
        printf("4. Insert at Beginning\n");
        printf("5. Insert at End\n");
        printf("6. Insert After Given Node\n");
        printf("7. Delete From Beginning\n");
        printf("8. Delete From End\n");
        printf("9. Delete Given Node\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: traverseForward(); break;
            case 3: traverseBackward(); break;
            case 4: insertBeginning(); break;
            case 5: insertEnd(); break;
            case 6: insertAfter(); break;
            case 7: deleteBeginning(); break;
            case 8: deleteEnd(); break;
            case 9: deleteGiven(); break;
            case 10: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}
