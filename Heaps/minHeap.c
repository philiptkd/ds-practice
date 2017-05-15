#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//includes the basic operations on a Min Heap

//create empty heap
struct minHeap* createEmptyMinHeap(int size)
{
    struct minHeap* h = (struct minHeap*)malloc(sizeof(struct minHeap));    //allocate memory for metadata
    h->arrSize = size;
    h->heapSize = 0;
    h->heapArr = (int*)malloc(size*sizeof(int));    //allocate memory for heap

    return h;
}

//returns the smallest element, the root
//takes O(1) time
int getMin(struct minHeap* h)
{
    if(h->heapSize <= 0)
        return INT_MAX;
    else
        return h->heapArr[0];

}

//removes the smallest element from the heap
//takes O(logn) time from minHeapify()
int extractMin(struct minHeap* h)
{
    if(h->heapSize <= 0)    //if the heap is empty, return INT_MAX
        return INT_MAX;

    if(h->heapSize == 1)    //if the heap has only one element, return that element
    {
        h->heapSize = 0;
        return h->heapArr[0];
    }

    int ret = h->heapArr[0];
    h->heapArr[0] = h->heapArr[h->heapSize - 1];    //replace the root with the rightmost leaf node
    h->heapSize = h->heapSize - 1;              //indicate the smaller size of the heap
    minHeapify(h, 0);              //convert new tree into heap
    return ret;
}

//inserts a new key into the heap
//takes O(logn) time from moveUpHeap()
void insertKey(struct minHeap* h, int key)
{
    if(h->heapSize == h->arrSize)       //do nothing if there is no room
        return;

    h->heapSize = h->heapSize + 1;      //increase size of heap
    h->heapArr[h->heapSize - 1] = key;  //add key to the end of the heap

    //move this key up the tree if it is less than its parent
    //the parent, previously less than its entire subtree, is still in a valid position after swapping
    moveUpHeap(h->heapArr, h->heapSize - 1);
}

//deletes key at index i from the heap
//takes O(logn) time
void deleteKey(struct minHeap* h, int i)
{
    if(i >= h->heapSize)    //ensure i is a valid index into the heap
        return;

    decreaseKey(h, i, INT_MIN);     //get this key to the top of the heap
    extractMin(h);                  //remove it
}

//decreases the key at an index to a specified new value
//takes O(logn) time from moveUpHeap()
void decreaseKey(struct minHeap* h, int i, int val)
{
    if(i >= h->heapSize)    //ensure i is a valid index into the heap
        return;

    h->heapArr[i] = val;           //update value at index i

    //move this key up the tree if it is less than its parent
    //the parent, previously less than its entire subtree, is still in a valid position after swapping
    moveUpHeap(h->heapArr, i);
}

void moveUpHeap(int* arr, int i)
{
    int p = parent(i);
    while(p >= 0 && arr[i] < arr[p])
    {
        swap(&arr[i], &arr[p]);
        i = p;
        p = parent(i);
    }
}

//recursively creates a heap out of an array
//assumes the subtrees of the root are heaps
//completes in O(logn) time
void minHeapify(struct minHeap* h, int i)
{
    int* arr = h->heapArr;

    int L = left(i);
    int R = right(i);
    int smallest = i;       //to hold index of the smallest key among those at i and its two children

    if(L < h->heapSize && arr[L] < arr[smallest])
        smallest = L;
    if(R < h->heapSize && arr[R] < arr[smallest])
        smallest = R;

    if(smallest != i)
    {
        swap(&arr[i], &arr[smallest]);  //if the smallest is not the parent, swap the parent and the smallest
        minHeapify(h, smallest);        //to ensure the key moved further down the tree is the smallest of its subtree
    }
}

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int left(int parent)
{
    return parent*2 + 1;
}

int right(int parent)
{
    return parent*2 + 2;
}

int parent(int i)
{
    return (i - 1)/2;   //works regardless of whether i is a left or right child because of the integer division
}

void printHeap(struct minHeap* h)
{
    int* arr = h->heapArr;
    int i;
    for(i=0; i<h->heapSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
