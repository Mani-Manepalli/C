#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Front and rear pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", x);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    int val = front->data;
    struct Node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    printf("Dequeued: %d\n", val);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
