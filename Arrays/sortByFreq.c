//sorts an array by the frequency of its elements
//for example, {3,2,1,2,3,4,4,5} -> {3,3,2,2,4,4,1,5}
//elements with higher frequency are listed first and grouped together by value
//elements of different value with the same frequency are listed in the order they appeared originally
//the strategy is to create an [N]x[3] array, storing with each value its original position and frequency
//the frequency is found by sorting on value and counting
//after frequency is found, the array is sorted on original position
//lastly, a stable sort is used to order by frequency
//uses O(n) auxiliary space and the sorting algorithms are the bottleneck on time ( O(n log n) )

#include <stdio.h>

void quickSortTriplet(int* arr, int origLeft, int origRight, int offset);
void descMergeSortByKey(int* arr, int* arrWorking, int start, int end, int depth);

void sortByFreq(int arr[], int N)
{
    //copy arr, with dimensions to hold original position and frequency data
    int i;
    int arrData[N][3];
    for(i=0; i<N; i++)
    {
        arrData[i][0] = arr[i];     //save value
        arrData[i][1] = i;          //save original position
        arrData[i][2] = 0;          //initialize freq to 0
    }

    //sort on value
    quickSortTriplet((int *)arrData, 0, N-2, 0);

    //I know I should abstract this out to its own function, but I don't know how without changing a lot of syntax, and I don't feel like doing that right now
    //calculate and store freq
    if(N == 1){ arrData[0][2] = 1; }    //handling trivial case
    int lastVal = arrData[0][0];
    int count = 1;
    for(i=1; i<N; i++)
    {
        if(arrData[i][0] == lastVal)
        {
            count++;
        }
        else
        {
            arrData[i-1][2] = count;
            count = 1;
            lastVal = arrData[i][0];
            if(i == N-1)
            {
                arrData[i][2] = 1;
            }
        }
    }

    //sort on original position
    quickSortTriplet((int *)arrData, 0, N-2, 1);

    int arrValAndFreq[N][2];    //creating a new array because I can and I don't want to rewrite my merge sort function for [N]x[3] arrays
    int arrWorking[N][2];   //working array for merge sort
    for(i=0; i<N; i++)      //initialize working array
    {
        arrValAndFreq[i][0] = arrData[i][0];
        arrValAndFreq[i][1] = arrData[i][2];
        arrWorking[i][0] = arrData[i][0];
        arrWorking[i][1] = arrData[i][2];
    }

    //sort (value,freq) array by freq. must be stable
    descMergeSortByKey((int *)arrValAndFreq, (int *)arrWorking, 0, N-1, 0);

    //print
    for(i=0; i<N; i++)
    {
        int j;
        for(j=0; j<arrValAndFreq[i][1]; j++)
        {
            printf("%d ", arrValAndFreq[i][0]);
        }
    }
}
