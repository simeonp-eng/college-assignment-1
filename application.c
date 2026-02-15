#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

void push(struct Stack *s, int value) {
    s->data[++(s->top)] = value;
}


int pop(struct Stack *s) {
    return s->data[(s->top)--];
}

int main() {
    struct Stack s;
    char postfix[MAX];
    int i, op1, op2, result;

    initStack(&s);

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; i < strlen(postfix); i++) {

        if(isdigit(postfix[i])) {
            push(&s, postfix[i] - '0'); 
        }

        
        else {
            op2 = pop(&s);
            op1 = pop(&s);

            switch(postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = op1 ^ op2; break; 
                default:
                    printf("Invalid Operator\n");
                    return 0;
            }

            push(&s, result);
        }
    }

    printf("Result = %d\n", pop(&s));

    return 0;
}
