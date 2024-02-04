#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node * next;
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int val);

// Insert a new head with given value and returns a pointer to the new head
// Runtime: O(1)
Node * insertHead(Node * head, int val);

// Insert a new tail with given value and returns a pointer to the new head
// Runtime: O(N)
Node * insertTail(Node * head, int val);

// Remove the head and returns a pointer to the new head
// Runtime: O(1)
Node * removeHead(Node * head);

// Remove the tail and returns a pointer to the new head
// Runtime: O(N)
Node * removeTail(Node * head);

// Check if the value
int contains(Node * head, int val);
Node * removeValue(Node * head, int val);
void printList(Node * head);

int main()
{
    Node * head = NULL;
    head = insertTail(head, 1);
    head = insertTail(head, 2);
    head = insertTail(head, 3);
    head = insertTail(head, 4);
    head = insertTail(head, 5);

    printList(head);

    head = removeHead(head);
    head = removeTail(head);

    printList(head);

    head = removeValue(head, 3);

    printList(head);

    return 0;
}

Node * createNode(int val)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

Node * insertHead(Node * head, int val)
{
    Node * newNode = createNode(val);

    newNode->next = head;
    
    return newNode;
}

Node * insertTail(Node * head, int val)
{
    if (head == NULL) return createNode(val);

    Node * cur = head;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = createNode(val);

    return head;
}

Node * removeHead(Node * head)
{
    if (head == NULL) return NULL;

    return head->next;
}

Node * removeTail(Node * head)
{
    if (head == NULL) return NULL;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    head->next = removeTail(head->next);

    return head;
}

int contains(Node * head, int val)
{
    if (head == NULL) return 0;

    if (head->data == val) return 1;

    return contains(head->next, val);
}

Node * removeValue(Node * head, int val)
{
    if (head == NULL) return NULL;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    if (head->next->data == val)
    {
        head->next = head->next->next;
        return head;
    }

    head->next = removeValue(head->next, val);

    return head;
}

void printList(Node * head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }

    printf("(%d) -> ", head->data);

    printList(head->next);
}