#include "main.h"

//the array of length N that's given is "nearly sorted",
//meaning that each element is at most k away from its sorted position
//this function sorts the array in O(N*logk) time using a min heap
void sortNearlySorted(int* arr, int N, int k)
{
    //create heap
    struct minHeap* h = createEmptyMinHeap(k);

    //populate it with first k elements in array
    int i;
    for(i=0; i<k; i++)
    {
        insertKey(h, arr[i]);
    }

    //put minimum at lowest index for each k-window
    for(i=0; i<N; i++)
    {
        arr[i] = extractMin(h);
        if(i+k < N)
            insertKey(h, arr[i+k]);
    }
}
