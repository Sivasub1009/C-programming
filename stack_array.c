#include <stdio.h>
#include<stdlib.h>
#define max 10
typedef struct Node{
    int item[max];
    int top;
}Node;

void createempty(Node* s)
{
    s->top=-1;
}

int full(Node* s)
{
    
        return (s->top==max-1);
    
}
int empty(Node* s)
{
  
        return (s->top==-1);
    
}

void push(Node* s,int data)
{
    if(full(s))
    {
        printf("the stack is full");
    }
    else{
        s->top++;
        s->item[s->top]=data;
    }
}
void pop(Node* s)
{
    if(empty(s))
    {
        printf("the stack is empty");
    }
    else{
       printf("the popped out item is : %d",s->item[s->top]);
       s->top--;
    }
}
int main()
{
    Node* s=(Node*)malloc(sizeof(Node));
createempty(s);
push(s,1);
push(s,2);
push(s,1);
push(s,55);
push(s,3);
pop(s);
return 0;
}
