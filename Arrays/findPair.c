#include <stdio.h>
#include <stdlib.h>

//finds if a pair of numbers in the input array sum to exactly X
//assumes input array arr[] is sorted
//arr[] : the array to be searched
//X : the sum
//len : the length of arr[]

void findPair(int arr[], int X, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        int toFind = X - arr[i];
        int leftBin = i + 1;
        int rightBin = len - 1;
        int midBin;

        while(leftBin < rightBin - 1)
        {
            midBin = (leftBin+rightBin)/2;
            if(arr[midBin] == toFind)
            {
                printf("Yes");
                return;
            }
            if(arr[midBin] < toFind)
            {
                leftBin = midBin;
            }
            else
            {
                rightBin = midBin;
            }
        }
    }

    printf("No");
}
