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

void insertEnd(int val) {
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

void sortList() {
    if(head == NULL) return;

    struct node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
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

int main() {
    int n, val;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(val);
    }

    sortList();
    traverse();

    return 0;
}
