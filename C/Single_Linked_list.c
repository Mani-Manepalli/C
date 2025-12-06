#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head = NULL;

void print_list()
{
    struct node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_beggining(int value)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) { printf("Memory allocation failed\n"); exit(1); }
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}
void insert_at_end(int value)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) { printf("Memory allocation failed\n"); exit(1); }
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
void delete_at_beggining()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}
void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void delete_at_position(int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (position == 0)
    {
        delete_at_beggining();
        return;
    }
    struct node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds. Cannot delete.\n");
        return;
    }
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void build_list_from_input()
{
    int n, val;
    printf("Enter number of initial elements (0 to skip): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Starting with empty list.\n");
        while (getchar() != '\n'); 
        return;
    }
    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i+1);
        if (scanf("%d", &val) != 1) {
            printf("Invalid value, stopping input.\n");
            while (getchar() != '\n'); 
            break;
        }
        insert_at_end(val);
    }
}

int main()
{
    int choice, value;
    build_list_from_input();  
    while (1)
    {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Delete at beginning\n4. Delete at end\n5. Delete  at Position\n6. Print list\n7. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input\n"); return 0; }
        if (choice == 7)
            break;
        if (choice == 6) {
            print_list();
            continue;
        }
        if (choice == 5) {
            int pos;
            printf("Enter position to delete: ");
            if (scanf("%d", &pos) != 1) { printf("Invalid input\n"); return 0; }
            delete_at_position(pos);
            print_list();
            continue;
        }
        if (choice == 3)
            delete_at_beggining();
        else if (choice == 4)
            delete_at_end();
        else if (choice != 1 && choice != 2) {
            printf("Invalid choice!\n");
            continue;
        }
        printf("Enter the value to insert: ");
        if (scanf("%d", &value) != 1) { printf("Invalid input\n"); return 0; }
        if (choice == 1)
            insert_at_beggining(value);
        else if (choice == 2)
            insert_at_end(value);
        else
            printf("Invalid choice!\n");
        print_list();
    }
    return 0;
}