#include "main.h"

//after every outer for loop, A[0...i-1] is sorted
//takes O(n^2) time

void insertionSort(int* A, int len)
{
    int i;
    for(i=1; i<len; i++)        //for each item in the array except the first
    {
        int key = A[i];

        int j;
        for(j=i; j>=0; j--)             //move to the left into its sorted place
        {
            if(j == 0 || key >= A[j-1])
            {
                A[j] = key;
                break;
            }

            //else if key < A[j-1]
            A[j] = A[j-1];
        }
    }
}
