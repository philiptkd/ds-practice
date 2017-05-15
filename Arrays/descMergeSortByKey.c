//descending merge sort by key
//sorts the portion of the array from "start" to "end"
//stable
//assumes arr and arrWorking are identical on the initial call

void mergeByKey(int* into, int* outOf, int start, int end);

void descMergeSortByKey(int* arr, int* arrWorking, int start, int end, int depth)
{
    if(start == end)    //single elements are sorted
        return;

    //merge left half
    descMergeSortByKey(arr, arrWorking, start, start + (end-start)/2, depth+1);

    //merge right half
    descMergeSortByKey(arr, arrWorking, start + (end-start)/2 + 1, end, depth+1);

    //merge two halves
    if(depth%2) //if depth is odd, merge into arrWorking
    {
        mergeByKey(arrWorking, arr, start, end);
    }
    else    //if depth is even, merge into arr
    {
        mergeByKey(arr, arrWorking, start, end);
    }
}

//descending merge sort by key
void mergeByKey(int* into, int* outOf, int start, int end)
{
    int intoIndex;
    int leftOutOfIndex = start, rightOutOfIndex = start + (end-start)/2 + 1;
    for(intoIndex=start; intoIndex<=end; intoIndex++)
    {
        if(leftOutOfIndex > start + (end-start)/2)          //if no more on left side, draw from right
        {
            *(into + intoIndex*2) = *(outOf + rightOutOfIndex*2);           //copy value
            *(into + intoIndex*2 + 1) = *(outOf + rightOutOfIndex*2 + 1);   //copy key
            rightOutOfIndex++;
        }
        else if(rightOutOfIndex > end)              //if no more on right side, draw from left
        {
            *(into + intoIndex*2) = *(outOf + leftOutOfIndex*2);           //copy value
            *(into + intoIndex*2 + 1) = *(outOf + leftOutOfIndex*2 + 1);   //copy key
            leftOutOfIndex++;
        }
        else if(*(outOf + rightOutOfIndex*2 + 1) > *(outOf + leftOutOfIndex*2 + 1)) //if next key on right is larger than that on left, draw from right
        {
            *(into + intoIndex*2) = *(outOf + rightOutOfIndex*2);           //copy value
            *(into + intoIndex*2 + 1) = *(outOf + rightOutOfIndex*2 + 1);   //copy key
            rightOutOfIndex++;
        }
        else        //if next key on left is same or greater than that on right, draw from left
        {
            *(into + intoIndex*2) = *(outOf + leftOutOfIndex*2);           //copy value
            *(into + intoIndex*2 + 1) = *(outOf + leftOutOfIndex*2 + 1);   //copy key
            leftOutOfIndex++;
        }

    }
}
