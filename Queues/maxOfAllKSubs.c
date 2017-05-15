#include "main.h"
#include <stdio.h>

//finds the maximum of every sub-array of length k
//does this by maintaining a deque of useful elements within the moving k-window
//a useful element is one that is greater than the elements to its right in the current k-window
//assumes k<=N
//uses O(N) time and O(k) extra space
//I cheated and looked at the answer for this one
void maxOfAllKSubs(int arr[], int N, int k)
{
    struct queueNode* deq = 0;

    //go over first k elements
    int i;
    for(i=0; i<k; i++)
    {
        //for each element, remove smaller elements to the left of it from deque
        while(!isEmptyDeque(deq) && arr[getBack(deq)] < arr[i])
        {
            deleteBack(&deq);
        }

        //put element on deque behind elements greater than it
        insertBack(&deq, i);
    }

    //go over rest of elements
    for(i=k; i<N; i++)
    {
        printf("%d ", arr[getFront(deq)]);       //print max for previous k-window

        //remove elements no longer in window from front of deque
        while(!isEmptyDeque(deq) && getFront(deq) <= i-k)
        {
            deleteFront(&deq);
        }

        //for each element, remove smaller elements to the left of it
        while(!isEmptyDeque(deq) && arr[getBack(deq)] < arr[i])
        {
            deleteBack(&deq);
        }

        //put element on deque behind elements greater than it
        insertBack(&deq, i);
    }

    //print max of last k-window
    printf("%d\n", arr[getFront(deq)]);
}
