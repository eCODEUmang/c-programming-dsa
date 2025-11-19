#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->prev = NULL;
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
            last = temp;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
}

void traverse() {
    struct node *p = head;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertAtBeginning(int val) {
    struct node *temp = createNode(val);

    if(head == NULL) {
        head = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtEnd(int val) {
    struct node *temp = createNode(val);

    if(head == NULL) {
        head = temp;
        return;
    }

    struct node *p = head;
    while(p->next != NULL)
        p = p->next;

    p->next = temp;
    temp->prev = p;
}

void insertAfter(int key, int val) {
    struct node *p = head;

    while(p != NULL && p->data != key)
        p = p->next;

    if(p == NULL) return;

    struct node *temp = createNode(val);

    temp->next = p->next;
    temp->prev = p;

    if(p->next != NULL)
        p->next->prev = temp;

    p->next = temp;
}

void deleteBeginning() {
    if(head == NULL) return;

    struct node *temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteEnd() {
    if(head == NULL) return;

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *p = head;
    while(p->next != NULL)
        p = p->next;

    p->prev->next = NULL;
    free(p);
}

void deleteByValue(int key) {
    if(head == NULL) return;

    if(head->data == key) {
        deleteBeginning();
        return;
    }

    struct node *p = head;
    while(p != NULL && p->data != key)
        p = p->next;

    if(p == NULL) return;

    if(p->next != NULL)
        p->next->prev = p->prev;

    p->prev->next = p->next;

    free(p);
}

int main() {
    int n;
    scanf("%d", &n);

    createList(n);
    traverse();

    insertAtBeginning(100);
    insertAtEnd(200);
    insertAfter(3, 150);

    traverse();

    deleteBeginning();
    deleteEnd();
    deleteByValue(150);

    traverse();

    return 0;
}
