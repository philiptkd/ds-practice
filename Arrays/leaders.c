//prints all leaders in an array
//an element is a "leader" if it is greater than all elements to its right
//the rightmost element is always a leader

#include <stdio.h>

void leaders(int arr[], int N)
{
    int bigLeader = arr[N-1];       //keeps track of the largest leader as we move left across the array
    printf("%d ", bigLeader);

    int i;
    for(i=N-2; i>=0; i--)
    {
        if(arr[i] > bigLeader)
        {
            bigLeader = arr[i];
            printf("%d ", bigLeader);
        }
    }
    printf("\n");
}
