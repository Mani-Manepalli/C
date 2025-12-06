#include <stdio.h>
#include <stdlib.h>

// BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert node into BST (duplicates ignored)
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    // else: duplicate - do nothing (you can change to handle duplicates if needed)

    return root;
}

// Search in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum value node (used in delete)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int val) {
    if (root == NULL) return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // node with two children: get inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Free the entire tree
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int choice, val, key;

    while (1) {
        printf("\n===== BST OPERATIONS =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            freeTree(root);
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &val) != 1) { printf("Invalid input\n"); break; }
                root = insert(root, val);
                printf("Inserted %d\n", val);
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &val) != 1) { printf("Invalid input\n"); break; }
                root = deleteNode(root, val);
                printf("Deleted %d (if it existed)\n", val);
                break;

            case 3:
                printf("Enter key to search: ");
                if (scanf("%d", &key) != 1) { printf("Invalid input\n"); break; }
                if (search(root, key) != NULL)
                    printf("Key %d found!\n", key);
                else
                    printf("Key %d not found!\n", key);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

}
