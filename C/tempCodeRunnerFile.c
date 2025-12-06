#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
struct Node* top = NULL; 
 
void push(int x) {     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));     newNode->data = x;     newNode->next = top;     top = newNode;     printf("Pushed: %d\n", x); 
} 
 
void pop() {     if (top == NULL) {         printf("Stack Underflow\n"); 
        return; 
    } 
    int val = top->data; 
    struct Node* temp = top;     top = top->next;     free(temp);     printf("Popped: %d\n", val); 
} 
 
int main() {     int choice, value; 
 
    while (1) {         printf("\n1. Push  2. Pop  3. Exit\n");         printf("Enter choice: ");         scanf("%d", &choice); 
 
        if (choice == 1) {             printf("Enter value: ");             scanf("%d", &value);             push(value); 
        } 
        else if (choice == 2) { 
            pop(); 
        } 
        else if (choice == 3) { 
            exit(0);         }         else {             printf("Invalid choice\n");         } 
    } 
 
    return 0; 
} 
