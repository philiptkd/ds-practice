#include "main.h"
#include <stdlib.h>

void radixCountingSort(int* A, int len, int bitsPerDigit, int digit);
int getMax(int* A, int len);
int numBitsUsed(int X);

void radixSort(int* A, int len, int bitsPerDigit)
{
    //get the largest element in the array
    int maxElem = getMax(A, len);

    //get the maximum number of bits needed to represent an element
    int maxBits = numBitsUsed(maxElem);

    //get number of digits/iterations for counting sort
    int digits = maxBits/bitsPerDigit;
    if(maxBits%bitsPerDigit)
        digits = digits + 1;

    //do counting sort on each digit
    int i;
    for(i=0; i<digits; i++)
    {
        radixCountingSort(A, len, bitsPerDigit, i);
    }
}

void radixCountingSort(int* A, int len, int bitsPerDigit, int digit)
{
    //max value + 1
    int k = 1 << bitsPerDigit;

    //a mask to get only the bits from the current digit
    int digitMask = (k - 1) << digit*bitsPerDigit;

    //create auxiliary array
    int* C = (int*)malloc(k*sizeof(int));

    //create output array
    int* B = (int*)malloc(len*sizeof(int));

    //initialize auxiliary array
    int i;
    for(i=0; i<k; i++)
    {
        C[i] = 0;
    }

    //create histogram
    for(i=0; i<len; i++)
    {
        int cIndex = (A[i]&digitMask) >> (digit*bitsPerDigit);
        C[cIndex] = C[cIndex] + 1;
    }

    //running sum to get number of elements <= index of C
    for(i=1; i<k; i++)
    {
        C[i] = C[i] + C[i-1];
    }

    //sort into output array
    for(i=len-1; i>=0; i--)
    {
        int cIndex = (A[i]&digitMask) >> (digit*bitsPerDigit);
        B[C[cIndex] - 1] = A[i];        //C[cIndex] holds the number of elements <= cIndex, so it is also the sorted index in B + 1
        C[cIndex] = C[cIndex] - 1;      //decrement value in C so equivalent elements don't collide
    }

    //put back into input array
    for(i=0; i<len; i++)
    {
        A[i] = B[i];
    }

    free(B);
    free(C);
}

//assumes A[] is nonempty
int getMax(int* A, int len)
{
    int maxElem = A[0];

    int i;
    for(i=1; i<len; i++)
    {
        if(A[i] > maxElem)
            maxElem = A[i];
    }
    return maxElem;
}

int numBitsUsed(int X)
{
    int bits = 0;
    do
    {
        X = X >> 1;
        bits = bits + 1;
    }while(X != 0);

    return bits;
}
