#include <stdio.h>

//prints an array of integers between two indices
//arr[] : array to be printed
//left : leftmost index of section of array to be printed
//right : rightmost index of section of array to be printed

void printList(int arr[], int left, int right)
{
    //print current state of list
    int i;
    for(i=left; i<=right; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

