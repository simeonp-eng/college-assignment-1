 #include <stdio.h>

#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void reversequeue() {
    for (int i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }
    for (int i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Original Queue: ");
    display();

    reversequeue();

    printf("Reversed Queue: ");
    display();

    return 0;
}


