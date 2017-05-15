//binary search to find an index of X in sorted array arr[] of length N
int findAnIndex(int arr[], int N, int X)
{
    //check endpoints
    if(arr[0] == X)
        return 0;
    if(arr[N-1] == X)
        return N-1;

    int left = 0;
    int right = N-1;
    int mid;

    while(left < right-1)
    {
        mid = (left + right)/2;
        if(arr[mid] == X)
            return mid;

        if(arr[mid] < X)
            left = mid;
        else    //if arr[mid] > X
            right = mid;
    }
    return -1;
}
