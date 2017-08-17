#include "main.h"
#include <time.h>
#include <stdlib.h>

//auxiliary functions
void swapElems(int* x, int* y);
void quickSortRec(int* A, int first, int last);
int qsPartition(int* A, int first, int last);


//takes O(n^2) time in the worst case
//  but O(nlgn) time on average
void quickSort(int* A, int len)
{
    // seeding the rand() function with the current time. need only be called once
    srand(time(NULL));

    //call the recursive function
    quickSortRec(A, 0, len-1);
}

void quickSortRec(int* A, int first, int last)
{
    if(last > first)
    {
        //choose a pseudo-random element of this subarray to be the pivot to reduce chances of worst-case partitions
        int pivot = rand()%(last-first+1) + first;

        //put the random pivot at the last index
        swapElems(&A[pivot], &A[last]);

        //get new position of pivot after partitioning
        int pivotIndex = qsPartition(A, first, last);

        //sort each subarray
        quickSortRec(A, first, pivotIndex-1);
        quickSortRec(A, pivotIndex+1, last);
    }
}

//quickSort partition
//after each for loop, A[first...i] contains only elements <= pivot
int qsPartition(int* A, int first, int last)
{
    //the pivot we partition around is the last element of this subarray
    int pivot = A[last];

    //let i mark the last index of the left partition
    int i = first - 1;

    int j;
    for(j=first; j<last; j++)       //for each element in the subarray
    {
        if(A[j] <= pivot)           //if it is <= pivot,
        {
            i = i + 1;                  //put it in the last position of the left partition
            swapElems(&A[j], &A[i]);    //j >= i, so the element that was at A[i] (that is by def'n > pivot) is still in the right partition
        }

        //if it is > pivot, increment j. it will remain in the right partition
    }

    //put the pivot in its sorted position, immediately to the right of the left partition
    swapElems(&A[i+1], &A[last]);

    return i+1;     //return the new index of the pivot
}

//swaps two integers given their pointers
void swapElems(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
