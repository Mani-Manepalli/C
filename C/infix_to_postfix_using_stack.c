#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c);
char pop();
int precedence(char c);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    gets(infix);  
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = c;
}


char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}


int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

   
        if (isalnum(c)) {
            postfix[j++] = c;
        }


        else if (c == '(') {
            push(c);
        }

     
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1 && stack[top] == '(')
                pop();
        }

      
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

   
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; 
}
