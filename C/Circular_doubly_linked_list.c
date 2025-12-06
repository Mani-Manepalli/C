#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n);
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayListForward();
void displayListBackward();

int main() {
    int choice, n, data, position;

    printf("******** CIRCULAR DOUBLY LINKED LIST IMPLEMENTATION ********\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Position\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter position and data to insert: ");
                scanf("%d %d", &position, &data);
                insertAtPosition(data, position);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 8:
                displayListForward();
                break;
            case 9:
                displayListBackward();
                break;
            case 10:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }

    head = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head;
    head->prev = head;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
        temp = newNode;
    }

    printf("Circular Doubly Linked List created successfully!\n");
}

void insertAtBeginning(int data) {
    struct Node *newNode, *last;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning successfully.\n");
}

void insertAtEnd(int data) {
    struct Node *newNode, *last;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    printf("Node inserted at end successfully.\n");
}

void insertAtPosition(int data, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    temp = head;

    for (i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && i != position - 1) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("Node inserted at position %d successfully.\n", position);
    }
}

void deleteAtBeginning() {
    struct Node *temp, *last;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        last = head->prev;

        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }

    printf("Node deleted from beginning successfully.\n");
}

void deleteAtEnd() {
    struct Node *last;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }

    printf("Node deleted from end successfully.\n");
}

void deleteAtPosition(int position) {
    struct Node *temp;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    temp = head;
    for (i = 1; i < position && temp->next != head; i++)
        temp = temp->next;

    if (temp == head) {
        printf("Position out of range.\n");
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
    }
}

void displayListForward() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("\nCircular Doubly Linked List (Forward): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

void displayListBackward() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head->prev;
    printf("\nCircular Doubly Linked List (Backward): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to head)\n");
}
