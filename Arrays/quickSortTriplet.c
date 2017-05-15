//uses the element at the last position as the pivot
//arr : array to be sorted
//origLeft : leftmost index of the portion of the array to be sorted
//origRight : rightmost index of the portion of the array to be sorted, not counting the pivot
//this version takes in array of size [N]x[3] and uses "offset" to determine which part of the triplet to sort on
void quickSortTriplet(int* arr, int origLeft, int origRight, int offset)
{
    int temp[3];
    int left = origLeft;
    int right = origRight;

    int pivot = right + 1;
    while(left <= right)
    {
        //for readability
        int leftVal = *(arr + left*3 + offset);
        int rightVal = *(arr + right*3 + offset);
        int pivotVal = *(arr + pivot*3 + offset);

        //if neither are on the right side, swap them
        if(!(leftVal < pivotVal) && !(rightVal > pivotVal))
        {
            int i;
            for(i=0; i<3; i++)
            {
                temp[i] = *(arr + right*3 + i);
                *(arr + right*3 + i) = *(arr + left*3 + i);
                *(arr + left*3 + i) = temp[i];
            }

            left++;
            right--;
        }
        else
        {
            if(leftVal < pivotVal)
            {
                left++;
            }
            if(rightVal > pivotVal)
            {
                right--;
            }
        }
    }

    //here left > right, so leftVal > pivotVal
    //swap items at left and pivot
    int i;
    for(i=0; i<3; i++)
    {
        temp[i] = *(arr + pivot*3 + i);
        *(arr + pivot*3 + i) = *(arr + left*3 + i);
        *(arr + left*3 + i) = temp[i];
    }

    pivot = left;
    //sort left half
    if(pivot - origLeft > 1)        //if there is more than one element to the left of the pivot
    {
        quickSortTriplet(arr, origLeft, pivot-2, offset);
    }

    //sort right half
    if(origRight+1 - pivot > 1)     //if there is more than one element to the right of the pivot
    {
        quickSortTriplet(arr, pivot+1, origRight, offset);
    }
}
