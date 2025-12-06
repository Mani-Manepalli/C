#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void createList(int n);
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayList();

struct Node* head = NULL;

int main() {
    int choice, n, data, position;

    printf("******** SINGLY LINKED LIST IMPLEMENTATION ********\n");

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
    struct Node *newNode, *temp;
    int data, i;

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
    head->next = NULL;

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
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }

    printf("Linked list created successfully!\n");
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;

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
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted at end successfully.\n");
}

void insertAtPosition(int data, int position) {
    int i;
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position %d successfully.\n", position);
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d successfully.\n", position);
    }
}

void deleteAtBeginning() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning successfully.\n");
}

void deleteAtEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }

    printf("Node deleted from end successfully.\n");
}

void deleteAtPosition(int position) {
    int i;
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
        return;
    }

    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
    }
}


void displayList() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("\nLinked List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
