#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n);
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayList();

int main() {
    int choice, n, data, position;

    printf("******** CIRCULAR LINKED LIST IMPLEMENTATION ********\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Position\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
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
                displayList();
                break;
            case 9:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createList(int n) {
    int data, i;
    struct Node *newNode, *temp;

    if (n <= 0) {
        printf("Number of nodes should be greater than zero.\n");
        return;
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head;  
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }

    printf("Circular linked list created successfully!\n");
}

void insertAtBeginning(int data) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning successfully.\n");
}

void insertAtEnd(int data) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
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

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && i != position - 1) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
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
        last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }

    printf("Node deleted from beginning successfully.\n");
}

void deleteAtEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }

    printf("Node deleted from end successfully.\n");
}

void deleteAtPosition(int position) {
    struct Node *temp, *prev;
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
    for (i = 1; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Position out of range.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
    }
}

void displayList() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("\nCircular Linked List elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

