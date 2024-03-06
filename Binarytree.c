#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* create(int data)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

Node* insert(Node* root,int data)
{
    if(!root)
    {
        return create(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

void inordertraversal(Node* root){
    if(root!=NULL)
    {
      
    inordertraversal(root->left);
    
    inordertraversal(root->right);
    printf("%d ",root->data);
    }
}
int main()
{
    Node* root=NULL;
    int arr[]={1,22,11,33,2,44};
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        root=insert(root,arr[i]);
    }
    inordertraversal(root);
    return 0;
}