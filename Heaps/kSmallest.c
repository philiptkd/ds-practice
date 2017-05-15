#include "main.h"
#include <stdio.h>
#include <stdlib.h>

//given an unsorted array, prints the k smallest elements
//does so by creating a minHeap and calling extractMin() k times
//takes O(k*logn) time
void kSmallest(int* arr, int N, int k)
{
    //create minHeap struct so we can use functions we already wrote
    struct minHeap* h = (struct minHeap*)malloc(sizeof(struct minHeap));
    h->arrSize = N;
    h->heapSize = N;
    h->heapArr = arr;

    //convert arr into heap, which apparently only takes O(N) time
    int i;
    for(i=N/2-1; i>=0; i--)
    {
        minHeapify(h, i);
    }

    //extract the smallest element k times, takes O(k*logn) time
    if(k > N)
        k = N;

    for(i=k-1; i>=0; i--)
    {
        printf("%d ", extractMin(h));
    }
    printf("\n");
}
