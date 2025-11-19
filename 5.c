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

int search(int key) {
    int pos = 1;
    struct node *p = head;

    while(p != NULL) {
        if(p->data == key)
            return pos;
        p = p->next;
        pos++;
    }
    return -1;
}

int main() {
    int n, val, key;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(val);
    }

    scanf("%d", &key);

    int pos = search(key);

    if(pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos);

    return 0;
}
