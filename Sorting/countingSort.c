#include "main.h"
#include <stdlib.h>

//assumes all values x in A are in the range 0 <= x < k
//stable. completes in O(len + k) time
void countingSort(int* A, int len, int k)
{
    //allocate memory for auxiliary arrays
    int* B = (int*)malloc(len*sizeof(int));
    int* C = (int*)malloc(k*sizeof(int));

    //initialize array
    int i;
    for(i=0; i<k; i++)
    {
        C[i] = 0;
    }

    //create in C a histogram of values in A
    //each index of C holds the number of elements in A that have that value
    for(i=0; i<len; i++)
    {
        C[A[i]] = C[A[i]] + 1;
    }

    //use running sum to get number of values in A that are <= i
    for(i=1; i<k; i++)
    {
        C[i] = C[i] + C[i-1];
    }

    //put in output array
    for(i=len-1; i>=0; i--)
    {
        B[C[A[i]] - 1] = A[i];      //since C[A[i]] holds the number of elements <= A[i], C[A[i]] is also that element's sorted index + 1
        C[A[i]] = C[A[i]] - 1;  //decrement index into B so that duplicate values aren't written to the same index
    }

    //copy back to A
    for(i=0; i<len; i++)
    {
        A[i] = B[i];
    }

    free(B);
    free(C);
}
