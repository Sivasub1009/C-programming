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

int isBalanced(Node* root) {
    if (root == NULL)
        return 1; // An empty tree is balanced
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1; // The tree is balanced
    return 0; // The tree is not balanced
}

int main() {
    Node* root = NULL;
    int arr[] = {11, 22, 22, 33, 33, 33,22};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    if (isBalanced(root))
        printf("The tree is balanced.\n");
    else
        printf("The tree is not balanced.\n");
    return 0;
}
