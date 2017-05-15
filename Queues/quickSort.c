//uses the element at the last position as the pivot
//arr[] : array to be sorted
//origLeft : leftmost index of the portion of the array to be sorted
//origRight : rightmost index of the portion of the array to be sorted, not counting the pivot

void quickSort(int arr[], int origLeft, int origRight)
{
    int temp;
    int left = origLeft;
    int right = origRight;

    int pivot = right + 1;
    while(left <= right)
    {
        //if neither are on the right side, swap them
        if(!(arr[left] < arr[pivot]) && !(arr[right] > arr[pivot]))
        {
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;

            left++;
            right--;
        }
        else
        {
            if(arr[left] < arr[pivot])
            {
                left++;
            }
            if(arr[right] > arr[pivot])
            {
                right--;
            }
        }
    }

    //here left > right, so arr[left] > arr[pivot]
    //swap items at left and pivot
    temp = arr[pivot];
    arr[pivot] = arr[left];
    arr[left] = temp;

    pivot = left;
    //sort left half
    if(pivot - origLeft > 1)        //if there is more than one element to the left of the pivot
    {
        quickSort(arr, origLeft, pivot-2);
    }

    //sort right half
    if(origRight+1 - pivot > 1)     //if there is more than one element to the right of the pivot
    {
        quickSort(arr, pivot+1, origRight);
    }
}
