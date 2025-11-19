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
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node *temp = createNode(val);

        if(head == NULL) {
            head = temp;
        } else {
            struct node *p = head;
            while(p->next != NULL)
                p = p->next;
            p->next = temp;
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
    temp->next = head;
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
}

void insertAfter(int key, int val) {
    struct node *p = head;
    while(p != NULL && p->data != key)
        p = p->next;

    if(p == NULL) return;  
    struct node *temp = createNode(val);
    temp->next = p->next;
    p->next = temp;
}

void deleteBeginning() {
    if(head == NULL) return;
    struct node *temp = head;
    head = head->next;
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
    while(p->next->next != NULL)
        p = p->next;

    free(p->next);
    p->next = NULL;
}

void deleteByValue(int key) {
    if(head == NULL) return;

    if(head->data == key) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *p = head;
    while(p->next != NULL && p->next->data != key)
        p = p->next;

    if(p->next == NULL) return;

    struct node *temp = p->next;
    p->next = temp->next;
    free(temp);
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
