#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    char data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

int isFull(struct Stack *s) {
    return (s->top == MAX - 1);
}

void push(struct Stack *s, char ch) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = ch;
}

char pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

char peek(struct Stack *s) {
    return s->data[s->top];
}

int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

int main() {
    struct Stack s;
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    initStack(&s);

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++) {
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if(infix[i] == '(') {
            push(&s, infix[i]);
        }

        
        else if(infix[i] == ')') {
            while(!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }

            if(isEmpty(&s)) {
                printf("Error: Mismatched Parentheses!\n");
                return 0;
            }
            pop(&s); 
        }

        
        else {
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while(!isEmpty(&s)) {
        if(peek(&s) == '(') {
            printf("Error: Mismatched Parentheses!\n");
            return 0;
        }
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
