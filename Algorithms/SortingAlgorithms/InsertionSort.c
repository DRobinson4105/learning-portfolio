#include <stdio.h>
#include <stdlib.h>

// Runtime:
// - Best: O(N)
// - Average: O(N^2)
// - Worst: O(N^2)

// Splits array into an unsorted part and a sorted part
// Repeatedly takes the first value of the unsorted part
// of the array and puts it in the correct position in
// the sorted array until there is no more values left
// array[] --> Array to be sorted
// size --> Size of array
void insertionSort(int * array, int size)
{
    int i, val;

    // Checking each value that is unsorted
    for(int curr = 1; curr < size; curr++)
    {
        // Takes first value of unsorted part of the array
        val = array[curr];

        // Shifting all values greater than the current value to the right
        for(i = curr - 1; i >= 0 && array[i] > val; i--) 
            array[i + 1] = array[i];

        // Inserting the current value in the right spot in the sorted part of the array
        array[i + 1] = val;
    }
}

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    insertionSort(array, size);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}