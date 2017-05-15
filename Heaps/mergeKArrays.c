#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//takes an array of pointers to sorted integer arrays
//uses a min heap to print them all in combined sorted order
//takes O(n*k*log(k)) time, where k is the number of int arrays and n is the number of elements in each int array
void mergeKArrays(int** arrList, int k, int n)
{
    //create array to hold answer, using O(n*k) extra space
    int* sortedArr = (int*)malloc(n*k*sizeof(int));
    int sortedIndex = 0;        //index for next element to be sorted into

    //create heap, using O(k) extra space
    struct minHeap* h = createEmptyMinHeap2(k);

    //create array to hold indices of the next elements in each of the k arrays, using O(k) extra space
    int* nexts = (int*)malloc(k*sizeof(int));
    int i;
    for(i=0; i<k; i++)
    {
        nexts[i] = 0;
    }

    //put first element of each array into one heap of size k
        //inserting k elements takes O(k*logk) time
    for(i=0; i<k; i++)
    {
        int testing = *(*(arrList + i) + 0);
        insertKey2(h, testing, i);    //insert element with the index of the array it came from
    }

    //while still elements to sort (multiply time by n*k)
    while(h->heapSize)
    {
        //extract the min into a sorted array of size n*k
            //extracting takes O(logk) time
        int* minPair = extractMin2(h);
        sortedArr[sortedIndex] = minPair[0];            //insert into final sorted array
        sortedIndex++;
        int j = minPair[1];     //to hold the index of the array the min came from

        free(minPair);

        nexts[j] = nexts[j] + 1;      //update next index for that input array

        //insert into the heap the next element of the array from which the late min came
            //inserting takes O(logk) time
        //if there is no next element in that array, the heap size will just be permanently reduced
        if(nexts[j] < n)
        {
            insertKey2(h, *( *(arrList + j) + nexts[j] ), j);
        }
    }

    for(i=0; i<n*k; i++)
    {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");
}
