#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
    int data; // Data that node holds
    Node * next; // Next node in a list or null if last node
};

struct LinkedList {
    Node * head; // First node in list
    Node * tail; // Last node in list
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

// Add a new value at the beginning of the list
void insertHead(LinkedList * list, int value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // If the list is empty
    if (isEmpty(list))
    {
        list->head = list->tail = newNode;
        return;
    }

    // Have the new head point to the old head
    newNode->next = list->head;

    // Save the new head of list
    list->head = newNode;
}

// Add a new value at the end of the list
void insertTail(LinkedList * list, int value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // If the list is empty
    if (isEmpty(list))
    {
        list->head = list->tail = newNode;
        return;
    }

    // Have the old tail point to the new tail
    list->tail->next = newNode;

    // Save the new tail
    list->tail = newNode;
}

// Remove first value in list
void removeHead(LinkedList * list)
{
    // If the list is empty
    if (isEmpty(list)) return;

    // If the list only has one node
    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = list->tail = NULL;
        return;
    }

    // Save pointer of old head
    Node * deletedNode = list->head;

    // Save the new head
    list->head = list->head->next;

    // Delete the old head
    free(deletedNode);
}

// Remove last value in list
void removeTail(LinkedList * list)
{
    // If the list is empty
    if (isEmpty(list->head)) return;

    // If the list only has one node
    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = list->tail = NULL;
        return;
    }

    // Get the pointer to the second to last node
    Node * curr = list->head;

    while (curr->next->next != NULL)
        curr = curr->next;

    // Delete the old tail
    free(curr->next);
    curr->next = NULL;

    // Save the new tail
    list->tail = curr;
}

// Free memory for all nodes in linked list
void deleteList(LinkedList * list)
{
    // While list is not empty
    while (!isEmpty(list))
        removeHead(list->head);
}

// Check if a linked list is empty
int isEmpty(LinkedList * list)
{
    return list->head == NULL;
}

// Print all values in a linked list
void printList(Node * head)
{
    while (head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("%d\n", head->data);
}

// Get node at specific index in linked list
Node * get(LinkedList * list, int index)
{
    // If index is invalid
    if (index < 0)
        return NULL;

    // Find node at given index in list
    Node * curr = list->head;

    for (int i = 0; i < index; i++)
    {
        curr = curr->next;

        // If index was higher than highest index in list
        if (curr == NULL)
            return NULL;
    }
        
    // Return node
    return curr;
}