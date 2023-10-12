#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    char data; // Data that node holds
    Node * next; // Next node in a list or null if last node
};

struct Stack {
    Node * top; // Top node in stack
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(char value);

// Add a new value to top of stack
void push(Stack * stack, char value);

// Remove the top value in stack
char pop(Stack * stack);

int priority(char c);

int main()
{
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    char expression[MAX_LENGTH];

    char c, temp;

    scanf("%s", expression);

    printf("%s\n", expression);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        c = expression[i];
        if (isalnum(c))
            printf("%c ", c);
        else if (c == '(')
            push(stack, c);
        else if (c == ')')
            while ((temp = pop(stack)) != '(')
                printf("%c ", temp);
        else
        {
            while (stack->top != NULL && priority(stack->top->data) >= priority(c))
                printf("%c ", pop(stack));
            push(stack, c);
        }
    }

    while(stack->top != NULL)
        printf("%c ", pop(stack));

    printf("\n");

    return 0;
}

Node * createNode(char value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and next parts of node
    newNode->data = value;
    newNode->next = NULL;

    // Return pointer to node
    return newNode;
}
void push(Stack * stack, char value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // Add new node to top of stack
    newNode->next = stack->top;

    // Save the new top
    stack->top = newNode;
}

char pop(Stack * stack)
{
    // If the stack is empty
    if (stack->top == NULL) return '\0';

    // Save pointer of top node
    Node * deletedNode = stack->top;
    char c = deletedNode->data;

    // Shift top of stack to next node
    stack->top = stack->top->next;

    // Free dynamic memory for removed node
    free(deletedNode);

    // Return deleted data
    return c;
}

int priority(char c)
{
    if (c =='+' || c == '-')
        return 1;

    if (c == '*' || c == '/')
        return 2;

    return 0;
}