#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert node into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Optional: free the entire tree to avoid memory leak
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int n, val, i;

    printf("How many nodes to insert? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of nodes\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &val) != 1) {
            printf("Invalid input\n");
            freeTree(root);
            return 1;
        }
        root = insert(root, val);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
