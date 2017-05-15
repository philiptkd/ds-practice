#include "main.h"

//given an array and its length, sorts it in O(n*logn) time
//does so in place and is stable
void heapSort(int* arr, int N)
{
    //make the array a heap. this takes O(n*logn) time
    int i;
    for(i=N/2-1; i>=0; i--)     //start at parent of rightmost leaf, move left across array towards root of tree
    {
        maxHeapify(arr, N, i);
    }

    //also O(n*logn)
    int heapSize = N;
    while(heapSize > 1)
    {
        //put max element at the end
        swap(&arr[0], &arr[heapSize-1]);

        //make the smaller array a heap
        maxHeapify(arr, heapSize-1, 0);

        //reduce heap size
        heapSize = heapSize - 1;
    }
}

//takes O(logn) time
void maxHeapify(int* arr, int N, int i)
{
    int L = left(i);
    int R = right(i);
    int largest;       //to hold index of the largest key among those at i and its two children

    //this initialization is important for making heapSort stable
    if(R < N)
        largest = R;
    else if(L < N)
        largest = L;
    else
        largest = i;

    //compare elements of array and choose the largest one, giving preference to those with larger indices
    if(L < N && arr[L] > arr[largest])
        largest = L;
    if(arr[i] > arr[largest])
        largest = i;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);  //if the largest is not the parent, swap the parent and the largest
        maxHeapify(arr, N, largest);        //to ensure the key moved further down the tree is the largest of its subtree
    }
}
