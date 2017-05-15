#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//the same as minHeap.c, but stores 2 ints for each tree node
//the 1st int is the key used in comparisons

//create empty heap
struct minHeap* createEmptyMinHeap2(int size)
{
    struct minHeap* h = (struct minHeap*)malloc(sizeof(struct minHeap));    //allocate memory for metadata
    h->arrSize = size*2;      //number of ints that the array holds
    h->heapSize = 0;        //number of int pairs in the heap
    h->heapArr = (int*)malloc(size*2*sizeof(int));    //allocate memory for heap

    return h;
}

//returns the smallest element, the root
//takes O(1) time
int* getMin2(struct minHeap* h)
{
    int* ret = (int*)malloc(2*sizeof(int));

    if(h->heapSize <= 0)
    {
        ret[0] = INT_MAX;
        ret[1] = INT_MAX;
        return ret;
    }
    else
    {
        ret[0] = h->heapArr[0];
        ret[1] = h->heapArr[1];
        return ret;
    }
}

//removes the smallest element from the heap
//takes O(logn) time from minHeapify()
int* extractMin2(struct minHeap* h)
{
    int* ret = (int*)malloc(2*sizeof(int));

    if(h->heapSize <= 0)    //if the heap is empty, return INT_MAX
    {
        ret[0] = INT_MAX;
        ret[1] = INT_MAX;
        return ret;
    }

    if(h->heapSize == 1)    //if the heap has only one element, return that element
    {
        h->heapSize = 0;
        ret[0] = h->heapArr[0];
        ret[1] = h->heapArr[1];
        return ret;
    }

    ret[0] = h->heapArr[0];     //save to return
    ret[1] = h->heapArr[1];

    h->heapArr[0] = h->heapArr[(h->heapSize - 1)*2];    //replace the root with the rightmost leaf node
    h->heapArr[1] = h->heapArr[(h->heapSize - 1)*2 + 1];

    h->heapSize = h->heapSize - 1;              //indicate the smaller size of the heap
    minHeapify2(h, 0);              //convert new tree into heap
    return ret;
}

//inserts a new key into the heap
//takes O(logn) time from moveUpHeap()
void insertKey2(struct minHeap* h, int key, int val2)
{
    if(h->heapSize*2 == h->arrSize)       //do nothing if there is no room
        return;

    h->heapSize = h->heapSize + 1;      //increase size of heap

    h->heapArr[(h->heapSize - 1)*2] = key;  //add key to the end of the heap
    h->heapArr[(h->heapSize - 1)*2 + 1] = val2;

    //move this key up the tree if it is less than its parent
    //the parent, previously less than its entire subtree, is still in a valid position after swapping
    moveUpHeap2(h->heapArr, (h->heapSize - 1)*2);
}

//deletes key at index i*2 and its associated second value at index i*2+1 from the heap
//takes O(logn) time
void deleteKey2(struct minHeap* h, int i)
{
    if(i >= h->heapSize*2)    //ensure i is a valid index into the heap
        return;

    decreaseKey2(h, i*2, INT_MIN);     //get this key to the top of the heap
    extractMin2(h);                  //remove it
}

//decreases the key at an index to a specified new value
//takes O(logn) time from moveUpHeap()
void decreaseKey2(struct minHeap* h, int i, int val)
{
    if(i >= h->heapSize*2)    //ensure i is a valid index into the heap
        return;

    h->heapArr[i] = val;           //update value at index i

    //move this key up the tree if it is less than its parent
    //the parent, previously less than its entire subtree, is still in a valid position after swapping
    moveUpHeap2(h->heapArr, i);
}

void moveUpHeap2(int* arr, int i)
{
    int p = parent2(i);
    while(p >= 0 && arr[i] < arr[p])
    {
        swap2(&arr[i], &arr[p]);
        swap2(&arr[i+1], &arr[p+1]);
        i = p;
        p = parent2(i);
    }
}

//recursively creates a heap out of an array
//assumes the subtrees of the root are heaps
//completes in O(logn) time
void minHeapify2(struct minHeap* h, int i)
{
    int* arr = h->heapArr;

    int L = left2(i);
    int R = right2(i);
    int smallest = i;       //to hold index of the smallest key among those at i and its two children

    if(L < h->heapSize*2 && arr[L] < arr[smallest])
        smallest = L;
    if(R < h->heapSize*2 && arr[R] < arr[smallest])
        smallest = R;

    if(smallest != i)
    {
        swap2(&arr[i], &arr[smallest]);  //if the smallest is not the parent, swap the parent and the smallest
        swap2(&arr[i+1], &arr[smallest+1]);

        minHeapify2(h, smallest);        //to ensure the key moved further down the tree is the smallest of its subtree
    }
}

void swap2(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int left2(int parent)
{
    return (parent*2 + 1)*2;
}

int right2(int parent)
{
    return (parent*2 + 2)*2;
}

int parent2(int i)
{
    return (i/2 - 1)/2;   //works regardless of whether i is a left or right child because of the integer division
}

void printHeap2(struct minHeap* h)
{
    int* arr = h->heapArr;
    int i;
    for(i=0; i<h->heapSize; i++)
    {
        printf("%d ", arr[i*2]);
    }
    printf("\n");
}
