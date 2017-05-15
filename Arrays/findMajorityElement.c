//finds the value that occurs at the majority of an array's indices, if there is one
//assumes the input array arr[] is sorted
//arr[] : array to be searched
//N : length of arr{}
//ans[] : array in which to store the answer

void findMajorityElement(int arr[], int N, int ans[])
{
    ans[0] = 0; ans[1] = 0;         //let a 0 as the first value indicate that there was no majority element
                                    //  and let the second value be the majority element, if it was found
    int count = 0;
    int i;
    for(i=0; i<N; i++)
    {
        if(i==0 || arr[i] != ans[1])
        {
            count = 1;
            ans[1] = arr[i];
        }
        else
        {
            count++;
            if(count > N/2)
            {
                ans[0] = 1;
                return;
            }
        }
    }
}
