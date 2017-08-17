#include "main.h"

#define PARENT(i) (i-1)/2
#define LEFT(i) i*2+1
#define RIGHT(i) i*2+2

//auxiliary functions
void buildMaxHeap(int* A, int len);
void maxHeapify(int* A, int heapSize, int root);
void swapElems(int* x, int* y);

void heapSort(int* A, int len)
{
    if(len == 1)
        return;

    //convert array into a max heap
    buildMaxHeap(A, len);

    //initialize heap size to be size of array
    int heapSize = len;

    int i;
    for(i=1; i<len; i++)    //only need to do len-1 times
    {
        //put max at end of heap
        swapElems(&A[0], &A[heapSize - 1]);

        //decrease heap size
        heapSize = heapSize - 1;

        //fix the heap. A[0] is probably not the heap max anymore
        maxHeapify(A, heapSize, 0);
    }
}

void buildMaxHeap(int* A, int len)
{
    //the last node with a child is the parent of the last node in the array
    int root = PARENT(len-1);

    //starting at the bottom of the tree, we build up the max heap
    for(; root>=0; root--)
    {
        maxHeapify(A, len, root);
    }
}

//assumes the subtrees of root are already max heaps
void maxHeapify(int* A, int heapSize, int root)
{
    //finds which of the root and its children is the largest
    int largest = root;
    if(LEFT(root) < heapSize && A[LEFT(root)] > A[largest])
        largest = LEFT(root);
    if(RIGHT(root) < heapSize && A[RIGHT(root)] > A[largest])
        largest = RIGHT(root);

    //if the root is not the max element in this subtree
    if(largest != root)
    {
        swapElems(&A[root], &A[largest]);   //put the largest at the root of the subtree
        maxHeapify(A, heapSize, largest);   //call again to ensure the subtree remains a max heap
    }
}
