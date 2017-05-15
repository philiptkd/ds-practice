#include "main.h"
#include <stdio.h>

void quickSort(int arr[], int origLeft, int origRight);

//takes in an array of digits 0-9 and prints the largest multiple of 3 those digits can be arranged to make
void largestMultipleOfThree(int arr[], int N)
{
    //sort the array
    quickSort(arr, 0, N-2);

    //queues to store digits with remainder 0, 1, and 2 after dividing by 3
    struct queueNode* q0 = 0;
    struct queueNode* q1 = 0;
    struct queueNode* q2 = 0;

    int sum = 0;
    int i;
    for(i=0; i<N; i++)              //separate into queues
    {
        sum = sum + arr[i];

        if(arr[i]%3 == 0)
        {
            enqueue(&q0, arr[i]);
        }
        else if(arr[i]%3 == 1)
        {
            enqueue(&q1, arr[i]);
        }
        else
        {
            enqueue(&q2, arr[i]);
        }
    }

    //a number is divisible by 3 if the sum of its digits is divisible by 3
    //because the array was sorted, any number taken off a queue will be the smallest number in that queue
    //we always prefer to remove 1 digit instead of 2 when possible
    if(sum%3 == 1)
    {
        if(!isEmpty(q1))
        {
            dequeue(&q1);       //subtracting this number from the sum will subtract 1 from the remainder of the sum
        }
        else
        {
            dequeue(&q2);       //subtracting these numbers from the sum will subtract 1 from the remainder of the sum
            dequeue(&q2);
        }
    }
    else if(sum%3 == 2)
    {
        if(!isEmpty(q2))
        {
            dequeue(&q2);       //subtracting this number from the sum will subtract 1 from the remainder of the sum
        }
        else
        {
            dequeue(&q1);       //subtracting these numbers from the sum will subtract 1 from the remainder of the sum
            dequeue(&q1);
        }
    }

    //if there are no more elements left in the queues, then there is no multiple of 3 possible with the given array
    if(isEmpty(q0) && isEmpty(q1) && isEmpty(q2))
    {
        printf("No solution.\n");
        return;
    }

    //dump remaining elements back into array
    i = 0;
    while(!isEmpty(q0))
    {
        arr[i] = dequeue(&q0);
        i++;
    }
    while(!isEmpty(q1))
    {
        arr[i] = dequeue(&q1);
        i++;
    }
    while(!isEmpty(q2))
    {
        arr[i] = dequeue(&q2);
        i++;
    }

    //fill the rest of the places with -1 to indicate they're empty
    while(i<=N-1)
    {
        arr[i] = -1;
        i++;
    }

    //sort again
    quickSort(arr, 0, N-2);

    //print backwards
    for(i=N-1; i>=0; i--)
    {
        if(arr[i] >= 0)
            { printf("%d ", arr[i]); }
    }
    printf("\n");
}
