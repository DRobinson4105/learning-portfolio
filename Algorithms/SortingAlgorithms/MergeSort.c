#include <stdio.h>
#include <stdlib.h>

// Runtime:
// - Best: O(NlogN)
// - Average: O(NlogN)
// - Worst: O(NlogN)

// Merges and sorts two subarrays of elements where 
// first subarray is array[L..M] and second subarray 
// is array[M+1..R]
// array[] --> Array to be sorted
// L --> Starting index
// R --> Ending index
// M --> Midpoint between L and R
void merge(int * array, int low, int high, int mid)
{
    int length1 = mid - low + 1;
    int length2 = high - mid;

    // Create temp arrays for left and right subarrays
    int * arrL = (int *) malloc(sizeof(int) * length1);
    int * arrR = (int *) malloc(sizeof(int) * length2);

    // Copy left and right subarray elements into temp arrays
    for(int i = 0; i < length1; i++)
        arrL[i] = array[i + low];

    for(int i = 0; i < length2; i++)
        arrR[i] = array[mid + 1 + i];

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray
    
    // Merge temp arrays back into array[L..R]
    while (i < length1 && j < length2)
    {
        // If arrL[i] is less than or equal to arrR[j] then add arrL[i] to the 
        // next index in the merged subarray and move to the next value in arrL[]
        if (arrL[i] <= arrR[j])
            array[k++] = arrL[i++];
        else
            array[k++] = arrR[j++];
    }
    
    // Copy any remaining elements in arrL[]
    while (i < length1)
        array[k++] = arrL[i++];
 
    // Copy any remaining elements in arrR[]
    while (j < length2)
        array[k++] = arrR[j++];

    // Free temp arrays
    free(arrL);
    free(arrR);
}

// Repeatedly splits array until each subarray has a 
// length of 1 or 0 and then merges and sorts the subarrays
// array[] --> Array to be sorted
// L --> Starting index
// R --> Ending index
void mergeSort(int * array, int low, int high)
{
    // If size of subarray is 0 or 1, do nothing
    if(low >= high) return;

    int mid  = (low + high) / 2; // Midpoint of subarray

    // Sort left and right halves of array
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    // Merge both halves together
    merge(array, low, high, mid);
}

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    mergeSort(array, 0, size - 1);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}