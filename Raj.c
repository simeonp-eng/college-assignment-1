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
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

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

 
void insertPosition(int value, int pos)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;

    if(pos == 1)
    {
        while(temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }

    for(int i = 1; i < pos-1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}
 
void display(int n)
{
    struct Node *temp = head;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, x, value, pos;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        create(x);
    }

    scanf("%d", &value);
    scanf("%d", &pos);

    insertPosition(value, pos);

    display(n + 1);

    return 0;
}