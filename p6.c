#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char *data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char *data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, char *data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else {
        if (strcmp(data, (*root)->data) < 0) {
            insert(&((*root)->left), data);
        } else if (strcmp(data, (*root)->data) > 0) {
            insert(&((*root)->right), data);
        }
    }
}

int tree_height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = tree_height(root->left);
        int rightHeight = tree_height(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

void print_level(struct Node* root, int level_no, int current_level) {
    if (!root)
        return;
    if (level_no == 0) {
        printf("Level %d: %s\n",current_level, root->data);
    } else {
        print_level(root->left, level_no - 1,current_level);
        print_level(root->right, level_no - 1,current_level);
    }
}

void print_tree_level_order(struct Node* root) {
    int height = tree_height(root);
    for (int i = 0; i < height; i++) {
        // Print the ith level
        print_level(root, i,i+1);
    }
}

bool search(struct Node* root, char *data) {
    if (root == NULL) {
        return false;
    } else if (strcmp(root->data, data) == 0) {
        return true;
    } else if (strcmp(data, root->data) < 0) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    struct Node* root = NULL;
    char *mnemonics[] = {"add", "sub", "mult", "div"};
    int mnemonicsCount = sizeof(mnemonics) / sizeof(mnemonics[0]);

    for (int i = 0; i < mnemonicsCount; i++) {
        insert(&root, mnemonics[i]);
    }

    printf("Level-wise display:\n");
    print_tree_level_order(root);
    printf("\n");

    char searchItem[100];
    printf("Enter the item to search: ");
    scanf("%s", searchItem);
    
    if (search(root, searchItem)) {
        printf("'%s' found in the tree.\n", searchItem);
    } else {
        printf("'%s' not found in the tree.\n", searchItem);
    }

    return 0;
}

