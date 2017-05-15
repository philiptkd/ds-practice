//finds the largest sum of a nonadjacent subsequence in arr[]
//in order to do this in O(n) time, we must be wary of strictly increasing portions of arr[]
//if we process the array one element at a time, adding elements to a strictly increasing array
    //changes whether all its previous elements are included in the largest sum or not
//so we keep track of both of the increasing series' alternating sums

int largestNonadjSub(int arr[], int N)
{
    int sum = 0;    //running sum of the largest nonadjacent subsequence
    int altSums[2] = {0, 0};    //both alternating sums of a contiguous strictly increasing subarray
    int i;      //index of element currently under consideration
    int increasingLen = 0;  //length of the current contiguous strictly increasing subarray

    //we start by adding the first element, assuming it is the beginning of an increasing subarray
    increasingLen++;
    altSums[increasingLen%2] = altSums[increasingLen%2] + arr[0];     //start with the first element in the subsequence

    for(i=1; i<N; i++)
    {
        if(increasingLen == 0)    //if the last element ended an increasing sequence (was lower than the one before it)
        {
            increasingLen++;
            altSums[increasingLen%2] = altSums[increasingLen%2] + arr[i];   //assumes altSums was reset already
        }
        else    //the last number was part of an increasing sequence
        {
            if(arr[i] <= arr[i-1])   //if this value is less than the last, it ends the last increasing sequence
            {
                sum = sum + altSums[increasingLen%2];   //add the larger altSum to sum
                altSums[0] = 0;
                altSums[1] = 0;
                increasingLen = 0;
            }
            else   //if this value is greater than the last, it continues the increasing subarray
            {
                increasingLen++;
                altSums[increasingLen%2] = altSums[increasingLen%2] + arr[i];
            }
        }
    }

    sum = sum + altSums[increasingLen%2];   //add the final increasing subseries
    return sum;
}
