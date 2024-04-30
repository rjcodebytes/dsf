#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    bool rightThread;
} Node;

// Function prototypes
Node* leftMost(Node* n);
void inOrder(Node* root);
Node* createNode(int val);
Node* insert(Node* root, int data);

// Function to find the leftmost node in a subtree
Node* leftMost(Node* n) {
    if (n == NULL)
        return NULL;

    while (n->left != NULL)
        n = n->left;

    return n;
}

// Function to perform inorder traversal in a threaded binary tree
void inOrder(Node* root) {
    Node* cur = leftMost(root);
    while (cur != NULL) {
        printf("%d-> ", cur->data);

        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rightThread)
            cur = cur->right;
        else // Else go to the leftmost child in the right
             // subtree
            cur = leftMost(cur->right);
    }
}

// Constructor function
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->rightThread = false;
    }
    return newNode;
}

// Function to insert a node into a threaded binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    Node* newNode = createNode(data);
    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                newNode->right = current;
                newNode->rightThread = true;
                return root;
            }
            current = current->left;
        } else {
            if (!current->rightThread) {
                current = current->right;
            } else {
                newNode->right = current->right;
                current->right = newNode;
                current->rightThread = false;
                return root;
            }
        }
    }

    if (parent->data < data) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
        newNode->right = parent;
        newNode->rightThread = true;
    }

    return root;
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
