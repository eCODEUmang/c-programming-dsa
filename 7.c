#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct DoublyList {
    Node *head;
    Node *tail;
    int size;
} DoublyList;

/* --- Basic helpers --- */
Node *createNode(int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}

void initList(DoublyList *L) {
    L->head = L->tail = NULL;
    L->size = 0;
}

void clearList(DoublyList *L) {
    Node *cur = L->head;
    while (cur) {
        Node *nx = cur->next;
        free(cur);
        cur = nx;
    }
    initList(L);
}

/* Insert at end (keeps tail updated) */
void insertEnd(DoublyList *L, int value) {
    Node *n = createNode(value);
    if (L->head == NULL) {
        L->head = L->tail = n;
    } else {
        L->tail->next = n;
        n->prev = L->tail;
        L->tail = n;
    }
    L->size++;
}

/* Print forward */
void printForward(DoublyList *L) {
    if (L->head == NULL) {
        printf("(empty)\n");
        return;
    }
    for (Node *p = L->head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

/* Print backward */
void printBackward(DoublyList *L) {
    if (L->tail == NULL) {
        printf("(empty)\n");
        return;
    }
    for (Node *p = L->tail; p != NULL; p = p->prev)
        printf("%d ", p->data);
    printf("\n");
}

/* Read n elements and append to list */
void inputList(DoublyList *L, int n) {
    int x;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &x) != 1) { printf("Invalid input\n"); exit(EXIT_FAILURE); }
        insertEnd(L, x);
    }
}

/* Concatenate B onto A. After this, B becomes empty. */
void concatenateLists(DoublyList *A, DoublyList *B) {
    if (B->head == NULL) return;       /* nothing to do */
    if (A->head == NULL) {
        /* A empty -> A takes B entirely */
        A->head = B->head;
        A->tail = B->tail;
        A->size = B->size;
    } else {
        /* link tails/heads */
        A->tail->next = B->head;
        B->head->prev = A->tail;
        A->tail = B->tail;
        A->size += B->size;
    }
    /* Make B empty (important!) */
    B->head = B->tail = NULL;
    B->size = 0;
}

/* --- Menu and main --- */
void showMenu(void) {
    printf("\nMenu\n");
    printf("1. Create List A\n");
    printf("2. Create List B\n");
    printf("3. Show List A\n");
    printf("4. Show List B\n");
    printf("5. Concatenate B onto A\n");
    printf("6. Show A forward, A backward\n");
    printf("7. Clear both lists and exit\n");
    printf("Enter option: ");
}

int main(void) {
    DoublyList A, B;
    initList(&A);
    initList(&B);

    int opt;
    while (1) {
        showMenu();
        if (scanf("%d", &opt) != 1) { puts("Bad input"); break; }

        if (opt == 1) {
            clearList(&A);
            int n;
            printf("Enter number of elements for List A: ");
            if (scanf("%d", &n) != 1 || n < 0) { puts("Invalid"); break; }
            if (n > 0) {
                printf("Enter %d integers:\n", n);
                inputList(&A, n);
            }
        } else if (opt == 2) {
            clearList(&B);
            int n;
            printf("Enter number of elements for List B: ");
            if (scanf("%d", &n) != 1 || n < 0) { puts("Invalid"); break; }
            if (n > 0) {
                printf("Enter %d integers:\n", n);
                inputList(&B, n);
            }
        } else if (opt == 3) {
            printf("List A (forward): ");
            printForward(&A);
            printf("List A (backward): ");
            printBackward(&A);
        } else if (opt == 4) {
            printf("List B (forward): ");
            printForward(&B);
            printf("List B (backward): ");
            printBackward(&B);
        } else if (opt == 5) {
            concatenateLists(&A, &B);
            printf("Concatenation done. List B is now empty.\n");
        } else if (opt == 6) {
            printf("A forward: ");
            printForward(&A);
            printf("A backward: ");
            printBackward(&A);
        } else if (opt == 7) {
            clearList(&A);
            clearList(&B);
            printf("Lists cleared. Exiting.\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
