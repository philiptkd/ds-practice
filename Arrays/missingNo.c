//given an array of numbers from 1 to N except one, finds the missing number
//assumes the length of arr[] is N-1
int missingNo(int arr[], int N)
{
    int sum = N*(N+1)/2;    //the sum of all integers 1 to N
    int thisSum = 0;
    int i;
    for(i=0; i<N-1; i++)    //the sum of the given array
    {
        thisSum = thisSum + arr[i];
    }

    return sum - thisSum;   //the difference is the missing number
}
