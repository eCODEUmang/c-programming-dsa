#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void createList(int n) {
    int val;
    struct node *last = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node *temp = createNode(val);

        if(head == NULL) {
            head = temp;
            temp->next = head;
            last = temp;
        } else {
            temp->next = head;
            last->next = temp;
            last = temp;
        }
    }
}

void traverseForward() {
    if(head == NULL) return;

    struct node *p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while(p != head);
    printf("\n");
}

void traverseBackward() {
    if(head == NULL) return;

    struct node *p = head;
    struct node *last = head;

    while(last->next != head)
        last = last->next;

    struct node *cur = last;

    do {
        printf("%d ", cur->data);

        struct node *prev = head;
        while(prev->next != cur)
            prev = prev->next;
        cur = prev;

    } while(cur != last);

    printf("\n");
}

void insertAtBeginning(int val) {
    struct node *temp = createNode(val);

    if(head == NULL) {
        head = temp;
        temp->next = head;
        return;
    }

    struct node *p = head;
    while(p->next != head)
        p = p->next;

    temp->next = head;
    p->next = temp;
    head = temp;
}

void insertAtEnd(int val) {
    struct node *temp = createNode(val);

    if(head == NULL) {
        head = temp;
        temp->next = head;
        return;
    }

    struct node *p = head;
    while(p->next != head)
        p = p->next;

    temp->next = head;
    p->next = temp;
}

void insertAfter(int key, int val) {
    if(head == NULL) return;

    struct node *p = head;
    do {
        if(p->data == key) {
            struct node *temp = createNode(val);
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    } while(p != head);
}

void deleteBeginning() {
    if(head == NULL) return;

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct node *p = head;
    while(p->next != head)
        p = p->next;

    struct node *temp = head;
    head = head->next;
    p->next = head;
    free(temp);
}

void deleteEnd() {
    if(head == NULL) return;

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct node *p = head;
    while(p->next->next != head)
        p = p->next;

    struct node *temp = p->next;
    p->next = head;
    free(temp);
}

void deleteByValue(int key) {
    if(head == NULL) return;

    if(head->data == key) {
        deleteBeginning();
        return;
    }

    struct node *p = head;
    do {
        if(p->next->data == key) {
            struct node *temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p = p->next;
    } while(p != head);
}

int main() {
    int n;
    scanf("%d", &n);

    createList(n);

    traverseForward();
    traverseBackward();

    insertAtBeginning(100);
    insertAtEnd(200);
    insertAfter(3, 150);

    traverseForward();
    traverseBackward();

    deleteBeginning();
    deleteEnd();
    deleteByValue(150);

    traverseForward();
    traverseBackward();

    return 0;
}
