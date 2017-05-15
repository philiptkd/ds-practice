//reverses an array in memory
//arr[] : the array to print
//N : the length of the array
//time complexity: O(n)
//auxiliary space: O(1)

#include <stdio.h>

void swapElems(int arr[], int x, int y);
void printList(int arr[], int left, int right);

void reverseArray(int arr[], int N)
{
    int i;
    for(i=0; i<N/2 - 1; i++)    //swap corresponding elements
    {
        swapElems(arr, i, N-1-i);
    }
    printList(arr, 0, N-1);
}
