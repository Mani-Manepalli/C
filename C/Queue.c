#include <stdio.h>
#include <stdlib.h>
#define MAX 100  

int queue[MAX];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();
int isEmpty();
int isFull();

int main() {
    int choice;

    printf("******** QUEUE IMPLEMENTATION USING ARRAY ********\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. INSERT (Enqueue)\n");
        printf("2. DELETE (Dequeue)\n");
        printf("3. DISPLAY\n");
        printf("4. Check if Queue is EMPTY\n");
        printf("5. Check if Queue is FULL\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    printf("\nQueue is EMPTY.\n");
                else
                    printf("\nQueue is NOT EMPTY.\n");
                break;
            case 5:
                if (isFull())
                    printf("\nQueue is FULL.\n");
                else
                    printf("\nQueue is NOT FULL.\n");
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
    return rear == MAX - 1;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void insert() {
    int value;

    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert element.\n");
    } else {
        printf("Enter value to INSERT: ");
        scanf("%d", &value);

        if (front == -1) 
            front = 0;

        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! No element to delete.\n");
    } else {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements (front to rear):\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
