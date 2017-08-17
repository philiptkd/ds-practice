#include "main.h"
#include <stdlib.h>

//auxiliary functions
void mergeSortRec(int* A, int* B, int first, int last, int depth);
void merge(int* into, int* outof, int first, int last);

void mergeSort(int* A, int len)
{
    //create auxiliary array to merge into and out of
    int* B = (int*)malloc(len*sizeof(int));

    int i;
    for(i=0; i<len; i++)    //copy A into B
    {
        B[i] = A[i];
    }

    //call recursive function
    mergeSortRec(A, B, 0, len-1, 0);
    free(B);
}

void mergeSortRec(int* A, int* B, int first, int last, int depth)
{
    if(last > first)    //do nothing for single elements. they are trivially sorted.
    {
        int mid = (first+last)/2;

        mergeSortRec(A, B, first, mid, depth+1);
        mergeSortRec(A, B, mid+1, last, depth+1);

        if(depth%2 == 0)            //if the depth is even,
            merge(A, B, first, last);   //merge into the original array.
        else                        //if the depth is odd,
            merge(B, A, first, last);   //merge into the other array
    }
}

//assumes the two subarrays to be merged are outof[first...mid] and outof[mid+1...last]
    //where mid = (first+last)/2
void merge(int* into, int* outof, int first, int last)
{
    int mid = (first+last)/2;   //last element of the left subarray in outof[]
    int nextL = first;          //the smallest element of the left subarray yet to be merged
    int nextR = mid+1;          //the smallest element of the right subarray yet to be merged

    int i;
    for(i=first; i<=last; i++)
    {
        //if there are no more elements on the right side,
            //or if the next (valid) element on the left is <= the next (valid) element on the right
        if(nextR > last || (nextL <= mid && outof[nextL] <= outof[nextR]))
        {
            into[i] = outof[nextL];     //draw from the left subarray
            nextL = nextL + 1;
        }
        //else, there is another element on the right and it's strictly less than the next valid element on the left
        else
        {
            into[i] = outof[nextR];     //draw from the right subarray
            nextR = nextR + 1;
        }
    }
}
