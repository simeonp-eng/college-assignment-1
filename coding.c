#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
 
void create(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}
 
void deleteLast()
{
    struct Node *temp = head, *prev;

    if(head == NULL)
        return;

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}
 
void display()
{
    struct Node *temp = head;

    if(head == NULL)
        return;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
}

int main()
{
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        create(x);
    }

    deleteLast();
    display();

    return 0;
}