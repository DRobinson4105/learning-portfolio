#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAP 10

typedef struct Heap Heap;

struct Heap {
    int * arr; // Array to hold values
    int size; // Current number of elements in array
    int cap; // Max number of elements in array
};

// Allocates memory for a heap with a starting capacity 
// for the array of 10 and returns a pointer to it
Heap * createHeap();

// Add value to end of heap
void append(Heap * pq, int value);

// Return index of parent of given index
int PARENT(int index);

// Return index of left child of given index
int LEFT(int index);

// Return index of right child of given index
int RIGHT(int index);

// Return first value in heap or -1 if heap is empty
int front(Heap * pq);

// Swap values at the given two indexes
void swap(Heap * pq, int index1, int index2);

// Recursive function to perculate the value at index up in the heap
void percUp(Heap * pq, int index);

// Add value to heap keeping the correct order of priority
void enqueue(Heap * pq, int value);

// Recursive function to perculate the value at index down in the heap
void percDown(Heap * pq, int index);

// Remove highest priority value in heap
void dequeue(Heap * pq);

// Print all values in heap
void printHeap(Heap * pq);

// Free all dynamic memory used in heap
void * freeHeap(Heap * pq);

int main()
{
    Heap * pq = createHeap();

    for (int i = 0; i < 10; i++)
    {
        int v = rand() % 100;
        printf("Inserting %d...\n", v);
        enqueue(pq, v);
        printf("The top is %d\n", front(pq));
    }

    printHeap(pq);

    pq = freeHeap(pq);

    return 0;
}

Heap * createHeap()
{
    // Allocate memory for heap
    Heap * newHeap = (Heap *) malloc(sizeof(Heap));

    // Initialize parts of heap
    newHeap->arr = (int *) malloc(sizeof(int) * STARTING_CAP);
    newHeap->size = 0;
    newHeap->cap = STARTING_CAP;
    
    // Return pointer to heap
    return newHeap;
}

void append(Heap * pq, int value)
{
    // If heap has not been initialized
    if (pq == NULL) return;

    // Double capacity of heap if heap is full
    if (pq->size == pq->cap)
    {
        pq->arr = (int *) realloc(pq->arr, pq->cap * 2);
        pq->cap *= 2;
    }

    // Add value to end of heap
    pq->arr[pq->size] = value;
    pq->size++;
}

int PARENT(int index)
{
    return (index - 1) / 2;
}

int LEFT(int index)
{
    return 2 * index + 1;
}

int RIGHT(int index)
{
    return 2 * index + 2;
}

int front(Heap * pq)
{
    // If heap has not been initialized or is empty
    if (pq == NULL || pq->size == 0)
        return -1;

    return pq->arr[0];
}

void swap(Heap * pq, int index1, int index2)
{
    int temp = pq->arr[index1];
    pq->arr[index1] = pq->arr[index2];
    pq->arr[index2] = temp;
}

void percUp(Heap * pq, int index)
{
    int pIndex = PARENT(index);
    if (index == 0) return; // root case

    // Check if better than parent
    if (pq->arr[index] < pq->arr[pIndex])
    {
        swap(pq, index, pIndex);
        percUp(pq, pIndex);
    }
}

void enqueue(Heap * pq, int value)
{
    append(pq, value);
    percUp(pq, pq->size - 1);
}

void percDown(Heap * pq, int index)
{
    int bestIndex = index;
    if (LEFT(index) < pq->size && pq->arr[LEFT(index)] < pq->arr[bestIndex])
        bestIndex = LEFT(index);
    if (RIGHT(index) < pq->size && pq->arr[RIGHT(index)] < pq->arr[bestIndex])
        bestIndex = RIGHT(index);

    // Check if we need to perc down
    if (bestIndex != index)
    {
        swap(pq, bestIndex, index);
        percDown(pq, bestIndex);
    }
}

void dequeue(Heap * pq)
{
    swap(pq, 0, pq->size - 1);

    pq->size--;

    if (pq->size)
        percDown(pq, 0);
}

void printHeap(Heap * pq)
{
    if (pq == NULL) return;

    for (int i = 0; i < pq->size; i++)
        printf("%d ", pq->arr[i]);

    printf("\n");
}

void * freeHeap(Heap * pq)
{
    if (pq == NULL) return NULL;

    free(pq->arr);
    free(pq);

    return NULL;
}