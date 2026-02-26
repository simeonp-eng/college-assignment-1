 #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int N, value;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &value);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}