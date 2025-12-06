#include <stdio.h>
#include <stdlib.h>
#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();
int isFull();
int isEmpty();

int main() {
    int choice;

    printf("******** CIRCULAR QUEUE IMPLEMENTATION USING ARRAY ********\n");

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
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
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
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insert() {
    int value;
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert element.\n");
        return;
    }

    printf("Enter value to INSERT: ");
    scanf("%d", &value);

    if (front == -1) 
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! No element to delete.\n");
        return;
    }

    printf("\nDeleted element: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        return;
    }

    printf("\nCircular Queue elements:\n");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
