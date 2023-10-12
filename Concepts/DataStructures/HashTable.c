#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 20
#define DEFAULT_STARTING_SIZE 100
#define NOT_FOUND_ERROR INT_MIN
#define LIST_LIMIT 5

typedef struct Node Node;
typedef struct HashTable HashTable;

struct Node {
    char * key;
    int value;
    Node * next;
};

struct HashTable {
    Node ** items;
    int size;
};

// Dynamically allocate memory for node, initializing it with the given key and value
// Return the pointer to that node
Node * createNode(char * key, int value);

// Uses string folding to create a hash index from 
// the given key and a max index of tableSize - 1
int sfold(char * key, int tableSize);

// Initialize a new hash table with the given starting size
HashTable * initialize(int startingSize);

// Insert a new node into the hash table with the given key and value
HashTable * insert(HashTable * table, char * key, int value);

// Find the node in the hash table with the given key and return the node's value
int search(HashTable * table, char * key);

// Delete a node from the hash table using the key
// Return 1 if node was deleted or 0 if node was not deleted
int delete(HashTable * table, char * key);

// Free all heap memory used by hash table
void freeHashTable(HashTable * table);

// Free all heap memory used by linked list
void freeLinkedList(Node * head);

// Resizes a hash table and recalculating each of the indexes of the nodes
HashTable * resize(HashTable * table, int newSize);

// Returns number of nodes in linked list
int getListSize(Node * head);

int main()
{
    HashTable * table = initialize(DEFAULT_STARTING_SIZE);
    char option = 'I';
    char key[MAX_STRING_LENGTH];
    int value;

    while (option != 'E')
    {   
        printf("HashTable:\n");
        printf("I) Insert new node\n");
        printf("D) Delete a node\n");
        printf("S) Search for a value\n");
        printf("E) Exit\n");
        printf("Option: ");

        scanf(" %c", &option);

        switch (toupper(option))
        {
            case 'I':
                printf("Key: ");
                scanf(" %s", key);
                printf("Value: ");
                scanf("%d", &value);

                table = insert(table, key, value);
                printf("%s has been added\n\n", key);

                break;

            case 'D':
                printf("Key: ");
                scanf(" %s", key);

                if (delete(table, key) == 1)
                    printf("%s has been deleted\n\n", key);
                else
                    printf("%s was not found\n\n", key);

                break;

            case 'S':
                printf("Key: ");
                scanf(" %s", key);
                
                value = search(table, key);

                if (value != NOT_FOUND_ERROR)
                    printf("%s's value is %d\n\n", key, value);
                else
                    printf("%s was not found\n\n", key);

                break;
        }
    }

    freeHashTable(table);
    return 0;
}

Node * createNode(char * key, int value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize key, value, and next parts of node
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // Return pointer to node
    return newNode;
}

int sfold(char * key, int tableSize)
{
    long long int sum = 0, mul = 1;
    int len = strlen(key);

    // Use folding on a string, summing 4 bytes at a time
    for (int i = 0; i < len; i++)
    {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += key[i] * mul;
    }

    // Returns the sum modded by the given table size
    return llabs(sum) % tableSize;
}

HashTable * initialize(int startingSize)
{
    HashTable * table = (HashTable *) malloc(sizeof(HashTable));

    table->size = startingSize;
    table->items = (Node **) malloc(sizeof(Node *) * startingSize);

    return table;
}

HashTable * insert(HashTable * table, char * key, int value)
{
    // Find index in hash table
    int hashIndex = sfold(key, table->size);
    
    Node * newNode = createNode(key, value);

    // Put the new node at the head of the linked list at that index
    newNode->next = table->items[hashIndex];
    table->items[hashIndex] = newNode;

    // Return a new hash table with double the indexes if the 
    // linked list at the hashIndex has 5 or more nodes
    if (getListSize(table->items[hashIndex]) >= LIST_LIMIT)
        return resize(table, table->size * 2);

    return table;
}

int search(HashTable * table, char * key)
{
    // Find index in hash table
    int hashIndex = sfold(key, table->size);

    Node * curr = table->items[hashIndex];

    while (curr != NULL)
    {
        // If key was found
        if (strcmp(key, curr->key) == 0)
            return curr->value;

        curr = curr->next;
    }

    // If key was not found
    return NOT_FOUND_ERROR;
}

int delete(HashTable * table, char * key)
{
    // Find index in hash table
    int hashIndex = sfold(key, table->size);

    // If no nodes are at the index
    if (table->items[hashIndex] == NULL) return 0;

    // If the key matches the head node at the index
    if (strcmp(key, table->items[hashIndex]->key) == 0)
    {
        Node * deletedNode = table->items[hashIndex];
        
        // Shift head node to next node
        table->items[hashIndex] = table->items[hashIndex]->next;

        // Free old head node
        free(deletedNode);

        return 1;
    }

    Node * curr = table->items[hashIndex];

    while (curr->next != NULL)
    {
        // If the key matches the next node
        if (strcmp(key, curr->next->key) == 0)
        {
            Node * deletedNode = curr->next;

            // Remove next node from linked list
            curr->next = curr->next->next;

            // Free that node
            free(deletedNode);

            return 1;
        }

        curr = curr->next;
    }

    return 0;
}

void freeHashTable(HashTable * table)
{
    for (int i = 0; i < table->size; i++)
        freeLinkedList(table->items[i]);

    free(table);
}

void freeLinkedList(Node * head)
{
    if (head == NULL) return;

    freeLinkedList(head->next);

    free(head);
}

HashTable * resize(HashTable * table, int newSize)
{
    HashTable * newTable = initialize(newSize);

    Node * curr;

    // For each linked list in the hash table
    for (int i = 0; i < table->size; i++)
    {
        // Set curr to the head of the current linked list
        curr = table->items[i];
        
        // Add each node from the linked list to the new hash table
        while (curr != NULL)
        {
            insert(newTable, curr->key, curr->value);

            curr = curr->next;
        }
    }

    // Free heap memory for old table
    freeHashTable(table);

    // Return new table
    return newTable;
}

int getListSize(Node * head)
{
    if (head == NULL) return 0;

    return 1 + getListSize(head->next);
}