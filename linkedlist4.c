 #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
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

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Element: %d", slow->data);

    return 0;
}