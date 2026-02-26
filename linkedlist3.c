 #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    struct node *head = NULL, *temp, *newnode;
    int N, value;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &value);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    head = reverseList(head);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}