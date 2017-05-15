#include "main.h"
#include <stdlib.h>

void mergeSortRecur(int* arr, int* arrWorking, int start, int end, int depth);
void mergeInto(int* into, int* outOf, int start, int end);

void mergeSort(int* arr, int N)
{
    //create auxiliary array to merge into and out of
    int* arrWorking = (int*)malloc(N*sizeof(int));

    //initializes arrWorking to be identical to arr
    int i;
    for(i=0; i<N; i++)
    {
        arrWorking[i] = arr[i];
    }

    mergeSortRecur(arr, arrWorking, 0, N-1, 0);
}

void mergeSortRecur(int* arr, int* arrWorking, int start, int end, int depth)
{
    if(start == end)    //single elements are already sorted
        return;

    //sort left half
    mergeSortRecur(arr, arrWorking, start, start + (end-start)/2, depth+1);

    //sort right half
    mergeSortRecur(arr, arrWorking, start + (end-start)/2 + 1, end, depth+1);

    //merge two halves
    if(depth%2) //if depth is odd, merge into arrWorking
    {
        mergeInto(arrWorking, arr, start, end);
    }
    else    //if depth is even, merge into arr
    {
        mergeInto(arr, arrWorking, start, end);
    }
}

void mergeInto(int* into, int* outOf, int start, int end)
{
    int leftOutOfIndex = start;
    int rightOutOfIndex = start + (end-start)/2 + 1;

    int intoIndex;
    for(intoIndex=start; intoIndex<=end; intoIndex++)
    {
        if(rightOutOfIndex > end)  //if no more on right, draw from left
        {
            into[intoIndex] = outOf[leftOutOfIndex];
            leftOutOfIndex++;
        }
        else if(leftOutOfIndex > start + (end-start)/2)  //if no more on left side, draw from right
        {
            into[intoIndex] = outOf[rightOutOfIndex];
            rightOutOfIndex++;
        }
        else if(outOf[leftOutOfIndex] <= outOf[rightOutOfIndex]) //if next on left is less than or equal to than next on right, draw from left
        {
            into[intoIndex] = outOf[leftOutOfIndex];
            leftOutOfIndex++;
        }
        else        //if next on right is less than next on left, draw from right
        {
            into[intoIndex] = outOf[rightOutOfIndex];
            rightOutOfIndex++;
        }
    }
}
