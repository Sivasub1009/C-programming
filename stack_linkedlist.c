#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of the stack
typedef struct {
    Node* top;
} Stack;

// Function to initialize an empty stack
void initialize(Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        return -1; // Return an arbitrary value to indicate underflow
    }
    Node* temp = stack->top;
    int poppedItem = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedItem;
}

// Function to get the top element of the stack without popping it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1; // Return an arbitrary value to indicate empty stack
    }
    return stack->top->data;
}

// Function to print the elements of the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory used by the stack
void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printStack(&stack);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped item: %d\n", pop(&stack));
    printf("Popped item: %d\n", pop(&stack));

    printStack(&stack);

    freeStack(&stack);

    return 0;
}