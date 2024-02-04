#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct Node {
    int data; // Data that node holds
    Node * next; // Next node in a list or null if last node
};

struct Queue {
    Node * front; // Next node in queue
    Node * rear; // Last node in queue
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
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

// Return the value that is next in queue
int peek(Queue * queue)
{
    // If the queue is empty
    if (isEmpty(queue))
        return -1;

    // Return next value in queue
    return queue->front->data;
}

// Remove the next value in queue
void dequeue(Queue * queue)
{
    // If the queue is empty
    if (isEmpty(queue)) return;

    // Save pointer of front node
    Node * deletedNode = queue->front;

    // Shift front of queue to next node
    queue->front = queue->front->next;

    // If there was only node in the queue
    if (isEmpty(queue))
        queue->rear = NULL;

    // Free dynamic memory for removed node
    free(deletedNode);
}

// Add a new value to end of queue
void enqueue(Queue * queue, int value)
{
    // Create node with inputed value
    Node * newNode = createNode(value);

    // If the queue is empty
    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
        return;
    }

    // Add new node to end of queue
    queue->rear->next = newNode;

    // Move the rear pointer to the new end of queue
    queue->rear = queue->rear->next;
}

// Free memory for all nodes in queue
void deleteQueue(Queue * queue)
{
    // While queue is not empty
    while (!isEmpty(queue))
        dequeue(queue);
}

// Check if a queue is empty
int isEmpty(Queue * queue)
{
    return queue->front == NULL;
}

// Print all values in queue starting at the front
void printQueue(Queue * queue)
{
    Node * curr = queue->front;
    
    // Print each value in the queue
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}