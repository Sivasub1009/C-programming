#include <stdio.h>


#include <stdlib.h>


 


// Define the structure for the nodes of the binary tree


typedef struct Node {


    int value;


    struct Node* left;


    struct Node* right;


} Node;


 


// Function to create a new node


Node* createNode(int value) {


    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode ==NULL) {       
printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value= value;
    newNode->left =NULL;
    newNode->right= NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insert(Node* root, int value) {
    if (root == NULL)
{        return createNode(value);
    }
    if (value <root->value) {
        root->left= insert(root->left, value);
    } else {
        root->right= insert(root->right, value);
    }
    return root;
}
// Function to perform in-order traversal of the tree
void inOrderTraversal(Node* root) {
    if (root != NULL)
{
     
inOrderTraversal(root->left);
printf("%d ", root->value);
      
inOrderTraversal(root->right);
    }
}


 


// Main function


int main() {


    Node* root = NULL;


    int arr[] = {20,15, 30, 10, 18, 25, 40};


    int n =sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i< n; i++) {


        root =insert(root, arr[i]);

    }
   
printf("Sorted elements: ");
 
inOrderTraversal(root);
   
printf("\n");
    return 0;


}