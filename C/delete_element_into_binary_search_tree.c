#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Insert element into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Find minimum value node (used in delete)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete element from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal to display BST contents
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) { printf("Invalid input\n"); return 1; }
                root = insert(root, value);
                printf("Inserted %d\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) { printf("Invalid input\n"); return 1; }
                root = deleteNode(root, value);
                printf("Deleted %d (if it existed)\n", value);
                break;

            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
