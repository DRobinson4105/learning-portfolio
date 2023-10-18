#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    double data; // Data that node holds
    Node * next; // Next node in a list or null if last node
};

struct Stack {
    Node * top; // Top node in stack
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(double value);

// Add a new value to top of stack
void push(Stack * stack, double value);

// Remove the top value in stack
double pop(Stack * stack);

int main()
{
    char expression[MAX_LENGTH];
    int len;
    int num1, num2;
    Stack * stack = (Stack *) malloc(sizeof(Stack));

    scanf("%s", expression);

    len = strlen(expression);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(expression[i]))
            push(stack, (int)expression[i] - 48);
        else
        {
            num2 = pop(stack);
            num1 = pop(stack);

            if (expression[i] == '+')
                push(stack, num1 + num2);
            else if (expression[i] == '-')
                push(stack, num1 - num2);
            else if (expression[i] == '*')
                push(stack, num1 * num2);
            else
                push(stack, num1 / num2);
        }

    }

    printf("%lf\n", stack->top->data);
    return 0;
}

Node * createNode(double value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and next parts of node
    newNode->data = value;
    newNode->next = NULL;

    // Return pointer to node
    return newNode;
}
void push(Stack * stack, double value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // Add new node to top of stack
    newNode->next = stack->top;

    // Save the new top
    stack->top = newNode;
}

double pop(Stack * stack)
{
    // If the stack is empty
    if (stack->top == NULL) return -1;

    // Save pointer of top node
    Node * deletedNode = stack->top;
    double num = deletedNode->data;

    // Shift top of stack to next node
    stack->top = stack->top->next;

    // Free dynamic memory for removed node
    free(deletedNode);

    // Return deleted data
    return num;
}