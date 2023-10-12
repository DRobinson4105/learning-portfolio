#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList ArrayList;

struct ArrayList {
    int size, cap;
    int * array;
};

// Allocates memory for an arraylist with the starting
// capacity for the array and returns a pointer to it
ArrayList * initialize(int startingCap)
{
    // Allocate memory for list
    ArrayList * newList = (ArrayList *) malloc(sizeof(ArrayList));

    // Initialize all parts of struct
    newList->cap = startingCap;
    newList->size = 0;
    newList->array = (int *) malloc(sizeof(int) * startingCap);

    return newList;
}

// Adds value to the end of the arraylist
void append(ArrayList * arraylist, int value)
{
    // Check if array is full and double capacity if so
    if(arraylist->size == arraylist->cap)
    {
        arraylist->cap *= 2;
        arraylist->array = realloc(arraylist->array, arraylist->cap);
    }

    // Add value to the end
    arraylist->array[arraylist->size] = value;
    arraylist->size++;
}

// Removes element at given index from the arraylist
void remove(ArrayList * arraylist, int index)
{
    // Shifts all elements to the right of array[index] to the left by one
    for(int i = index; i < arraylist->size - 1; i++)
        arraylist->array[i] = arraylist->array[i + 1];

    // Decrease the size by one
    arraylist->size--;
}

// Adds value to the arraylist at the given index
void insert(ArrayList * arraylist, int value, int index)
{
    // Check if array is full and double capacity if so
    if(arraylist->size == arraylist->cap)
    {
        arraylist->cap *= 2;
        arraylist->array = realloc(arraylist->array, arraylist->cap);
    }

    // Shifts all elements to the right of array[index] including index to the right by one
    for(int i = arraylist->size; i > index; i--)
        arraylist->array[i] = arraylist->array[i - 1];

    // Adds value at the given index
    arraylist->array[index] = value;
    arraylist->size++;
}

// Prints arraylist with brackets as [n1, n2, ...]
void printList(ArrayList * arraylist)
{
    printf("[");

    // Print elements with commas in between them
    for(int i = 0; i < arraylist->size; i++)
        printf((i < arraylist->size - 1) ? "%d, " : "%d]\n", arraylist->array[i]);
}

// Reverse order of elements in arraylist
void reverseList(ArrayList * arraylist)
{
    // Swap each set of outer values
    for(int i = 0; i < arraylist->size / 2; i++)
        swap(&arraylist->array[i], &arraylist->array[arraylist->size - 1 - i]);
}

// Swap values that num1 and num2 point to
void swap(int * num1, int * num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Merges and sorts two subarrays of elements where 
// first subarray is array[L..M] and second subarray 
// is array[M+1..R]
// L --> Starting index
// R --> Ending index
// M --> Midpoint between L and R
void merge(ArrayList * arraylist, int L, int R, int M)
{
    int length1 = M - L + 1;
    int length2 = R - M;

    // Create temp arrays for left and right subarrays
    int * arrL = (int *) malloc(sizeof(int) * length1);
    int * arrR = (int *) malloc(sizeof(int) * length2);

    // Copy left and right subarray elements into temp arrays
    for(int i = 0; i < length1; i++)
        arrL[i] = arraylist->array[i + L];

    for(int i = 0; i < length2; i++)
        arrR[i] = arraylist->array[M + 1 + i];

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = L; // Initial index of merged subarray
    
    // Merge temp arrays back into array[L..R]
    while (i < length1 && j < length2)
    {
        // If arrL[i] is less than or equal to arrR[j] then add arrL[i] to the 
        // next index in the merged subarray and move to the next value in arrL[]
        if (arrL[i] <= arrR[j])
            arraylist->array[k++] = arrL[i++];
        else
            arraylist->array[k++] = arrR[j++];
    }
    
    // Copy any remaining elements in arrL[]
    while (i < length1)
        arraylist->array[k++] = arrL[i++];
 
    // Copy any remaining elements in arrR[]
    while (j < length2)
        arraylist->array[k++] = arrR[j++];

    // Free temp arrays
    free(arrL);
    free(arrR);
}

// Repeatedly splits array until each subarray has a 
// length of one and then merges and sorts the subarrays
// L --> Starting index
// R --> Ending index
void sortList(ArrayList * arraylist, int L, int R)
{
    if(L < R)
    {
        int M = L + (R - L) / 2;

        // Sort left and right halves of array
        sortList(arraylist, L, M);
        sortList(arraylist, M + 1, R);

        // Merge both halves together
        merge(arraylist, L, R, M);
    }
}

// Free memory for arraylist
void deleteList(ArrayList * arraylist)
{
    free(arraylist->array);
    free(arraylist);
}