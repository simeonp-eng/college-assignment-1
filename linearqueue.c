#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("%d inserted\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d removed\n", queue[front++]);
    }
}

void findElement(int key) {
    int i, found = 0;

    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (i = front; i <= rear; i++) {
        if (queue[i] == key) {
            printf("Element %d found at position %d\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element %d not found\n", key);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    findElement(20);
    findElement(40);

    return 0;
}