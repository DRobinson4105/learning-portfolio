#include <stdio.h>
#include <stdlib.h>

// Runtime:
// - Best: O(N)
// - Average: O(N^2)
// - Worst: O(N^2)

// Swap values that num1 and num2 point to
void swap(int * num1, int * num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Starts with the whole array as the unsorted subarray,
// repeatedly moving the highest value to the end and
// decreasing unsorted subarray length by 1
// array[] --> Array to be sorted
// size --> Size of array
void bubbleSort(int * array, int size)
{
    // Decrease size of unsorted subarray after every iteration until size is 1
    for(int max = size; max > 1; max--)
    {
        // Iterate through subarray array[0..max - 1], swapping 
        // values if current value is greater than next value
        for (int j = 0; j < max - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
    }
}

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    bubbleSort(array, size);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}