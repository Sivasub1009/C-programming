#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* insert(Node* root, int data) {
    if (!root) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL)
        return -1; // Height of an empty tree is -1
    else
        return 1 + max(height(root->left), height(root->right));
}

int main() {
    Node* root = NULL;
    int arr[] = {1, 22, 11, 33, 2, 44};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\nHeight of the tree: %d\n", height(root));
    return 0;
}
