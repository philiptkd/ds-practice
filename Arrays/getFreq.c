//given one index j of value X in a sorted array arr[], counts the number of occurrences X
int getFreq(int arr[], int N, int j)
{
    int count = 1;
    int i = j;      //working index

    //look left
    while(i > 0 && arr[i-1] == arr[j])
    {
        count++;
        i--;
    }

    i = j;
    //look right
    while(i < N-1 && arr[i+1] == arr[j])
    {
        count++;
        i++;
    }

    return count;
}
