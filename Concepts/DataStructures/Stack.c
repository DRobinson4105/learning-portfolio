#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    int data; // Data that node holds
    Node * next; // Next node in a list or null if last node
};

struct Stack {
    Node * top; // Top node in stack
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value);

// Add a new value to top of stack
void push(Stack * stack, int value);

// Remove the top value in stack
Node * pop(Stack * stack);

// Return the value that is at the top of the stack
int top(Stack * stack);

// Free memory for all nodes in stack
void freeStack(Stack * stack);

// Check if a stack is empty
int isEmpty(Stack * stack);

// Print all values in stack starting at the top
void printStack(Stack * stack);

Node * createNode(int value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and next parts of node
    newNode->data = value;
    newNode->next = NULL;

    // Return pointer to node
    return newNode;
}

void push(Stack * stack, int value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // Add new node to top of stack
    newNode->next = stack->top;

    // Save the new top
    stack->top = newNode;
}

Node * pop(Stack * stack)
{
    // If the stack is empty
    if (isEmpty(stack)) return;

    // Save pointer of top node
    Node * deletedNode = stack->top;

    // Shift top of stack to next node
    stack->top = stack->top->next;

    // Free dynamic memory for removed node
    free(deletedNode);
}

int top(Stack * stack)
{
    // If the stack is empty
    if (isEmpty(stack))
        return -1;

    // Return top value in stack
    return stack->top->data;
}

void freeStack(Stack * stack)
{
    // While stack is not empty
    while (!isEmpty(stack))
        pop(stack);
}

int isEmpty(Stack * stack)
{
    return stack->top == NULL;
}

void printStack(Stack * stack)
{
    Node * curr = stack->top;
    
    // Print each value in the stack
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}