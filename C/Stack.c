#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

int stack[MAX];
int top = -1;  
void push();
void pop();
void display();
int isEmpty();
int isFull();

int main() {
    int choice;

    printf("******** STACK IMPLEMENTATION USING ARRAY ********\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. Check if Stack is EMPTY\n");
        printf("5. Check if Stack is FULL\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    printf("\nStack is EMPTY.\n");
                else
                    printf("\nStack is NOT EMPTY.\n");
                break;
            case 5:
                if (isFull())
                    printf("\nStack is FULL.\n");
                else
                    printf("\nStack is NOT FULL.\n");
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}


int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push() {
    int value;
    if (isFull()) {
        printf("\nStack Overflow! Cannot push element.\n");
    } else {
        printf("Enter value to PUSH: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! No element to pop.\n");
    } else {
        printf("\nPopped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
