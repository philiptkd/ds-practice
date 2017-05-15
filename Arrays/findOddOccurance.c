//assumes the maximum length of the input array is 201
//assumes the largest value in the array is no more than 1000
//assumes there is exactly one element that occurs an odd number of times

//arr[] : array to be searched
//N : length of array

int findOddOccurance(int arr[], int N)
{
    int histogram[1001];
    int i;

    //initialize array
    for(i=0; i<1001; i++)
    {
        histogram[i] = 0;
    }

    //count
    for(i=0; i<N; i++)
    {
        histogram[arr[i]]++;
    }

    //find the odd one
    for(i=0; i<1001; i++)
    {
        if(histogram[i]%2 == 1)
        {
            return i;
        }
    }

    return -1;
}
