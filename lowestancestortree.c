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

Node* LCA(Node* root, int node1, int node2) {
    if (root == NULL)
        return NULL;
    
    if (root->data > node1 && root->data > node2)
        return LCA(root->left, node1, node2);
    
    if (root->data < node1 && root->data < node2)
        return LCA(root->right, node1, node2);
    
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {1, 22, 11, 33, 2, 44};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    int node1 = 11, node2 = 33;
    Node* lca = LCA(root, node1, node2);
    if (lca)
        printf("Lowest Common Ancestor of %d and %d is %d\n", node1, node2, lca->data);
    else
        printf("Lowest Common Ancestor of %d and %d doesn't exist\n", node1, node2);
    
    return 0;
}