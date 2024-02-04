#include <stdio.h>
#include <stdlib.h>

// Runtime:
// - Best: O(N^2)
// - Average: O(N^2)
// - Worst: O(N^2)

// Swap values that num1 and num2 point to
void swap(int * num1, int * num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Repeatedly finds lowest value in array and puts it
// at the front of the unsorted part of the array until
// only last value is left
// array[] --> Array to be sorted
// size --> Size of array
void selectionSort(int * array, int size)
{
    int lowest;

    // Repeating process for every sub array[i..size-1] which is the unsorted part
    for(int i = 0; i < size - 1; i++)
    {
        // Find lowest value in the unsorted part of the array
        lowest = i;
        for(int j = i; j < size; j++)
            if(array[j] < array[lowest]) lowest = j;

        // Put lowest value in the unsorted part to the front
        swap(&array[i], &array[lowest]);
    }
}

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    selectionSort(array, size);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}