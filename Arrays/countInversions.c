//this is a merge sort that keeps track of number of inversions
//an inversion is when arr[i] > arr[j] and i<j

void merge(int* into, int* outOf, int start, int end, int* count);

void countInversions(int arr[], int arrWorking[], int start, int end, int depth, int* count)
{
    if(start == end)    //single elements are sorted
        return;

    //merge left half
    countInversions(arr, arrWorking, start, start + (end-start)/2, depth+1, count);

    //merge right half
    countInversions(arr, arrWorking, start + (end-start)/2 + 1, end, depth+1, count);

    //merge two halves
    if(depth%2) //if depth is odd, merge into arrWorking
    {
        merge(arrWorking, arr, start, end, count);
    }
    else    //if depth is even, merge into arr
    {
        merge(arr, arrWorking, start, end, count);
    }
}

//descending merge sort by key
void merge(int into[], int outOf[], int start, int end, int* count)
{
    int intoIndex;
    int leftOutOfIndex = start, rightOutOfIndex = start + (end-start)/2 + 1;
    for(intoIndex=start; intoIndex<=end; intoIndex++)
    {
        if(leftOutOfIndex > start + (end-start)/2)          //if no more on left side, draw from right
        {
            into[intoIndex] = outOf[rightOutOfIndex];           //copy value
            rightOutOfIndex++;
        }
        else if(rightOutOfIndex > end)              //if no more on right side, draw from left
        {
            into[intoIndex] = outOf[leftOutOfIndex];           //copy value
            leftOutOfIndex++;
        }
        else if(outOf[rightOutOfIndex] < outOf[leftOutOfIndex]) //if next value on right is less than that on left, draw from right
        {
            into[intoIndex] = outOf[rightOutOfIndex];           //copy value
            *count = *count + rightOutOfIndex - intoIndex;
            rightOutOfIndex++;
        }
        else        //if next value on left is same or less than that on right, draw from left
        {
            into[intoIndex] = outOf[leftOutOfIndex];           //copy value
            leftOutOfIndex++;
        }

    }
}

