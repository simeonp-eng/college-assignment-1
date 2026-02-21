#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d removed\n", queue[front]);

    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void findElement(int key) {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    i = front;
    while (1) {
        if (queue[i] == key) {
            printf("Element %d found\n", key);
            return;
        }
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("Element %d not found\n", key);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    dequeue();
    dequeue();

    enqueue(50);
    enqueue(60);

    findElement(30);
    findElement(70);

    return 0;
}