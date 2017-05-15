//finds the highest local min in an array for each possible width
//so, finds the highest local min over 2 indexes, 3 indexes, etc. up to N indexes for an N-long array
//does this in O(n) time by using a variation of nextLarger()

#include "main.h"
#include <stdlib.h>

int* nextSmaller(int* arr, int N);
int* prevSmaller(int* arr, int N);

int* highestLocalMin(int* data, int N)
{
    //in the ith place, stores the element of data that is the highest local min of i+1 width
    int* ans = (int*)malloc(N*sizeof(int));

    int* nextSmall = nextSmaller(data, N);        //for each element, gets the next element to the right smaller than it
    int* prevSmall = prevSmaller(data, N);        //for each element, gets the next element to the left smaller than it

    int* largestWindow = (int*)malloc(N*sizeof(int));   //for each element, to hold the largest width over which it is a local min
    int i;
    for(i=0; i<N; i++)
    {
        largestWindow[i] = nextSmall[i] - prevSmall[i] - 1;
        ans[i] = 0;                 //initializing answer array to 0
    }

    for(i=0; i<N; i++)
    {
        if(data[i] > ans[largestWindow[i] - 1])               //find the largest of the local mins with the same max width
        {
            ans[largestWindow[i] - 1] = data[i];
        }
    }

    //for those widths that are not claimed by any element as their max width,
        //give to those elements who claim a higher max width.
        //note that the global minimum will always have max width of N
    for(i=N-2; i>=0; i--)
    {
        if(ans[i+1] > ans[i])
        {
            ans[i] = ans[i+1];
        }
    }

    return ans;
}
