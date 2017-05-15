#include <stdio.h>

//finds the contiguous subarray of arr[] with the largest sum
//the idea is that any subarray on an "end" of an array with a net negative sum should be disconnected
//arr[] : the array to search
//origLeft : the leftmost index of the array to search
//origRight : the rightmost index of the array to search
int largestSubArray(int arr[], int origLeft, int origRight)
{
    int left = origLeft;
    int right = origRight;

    //handle wrong case
    if(left > right)
    {
        printf("Something's wrong!");
        return 0;
    }

    //handle single element case
    if(left == right)
        return arr[left];

    //trim negative numbers off ends
    while(arr[left] < 0)
    {
        left++;

        //if all were negative, return least negative value
        if(left > right)
        {
            int leastNegative = arr[origLeft];
            int i;
            for(i=origLeft; i<=origRight; i++)
            {
                if(arr[i] > leastNegative)
                    leastNegative = arr[i];
            }
            return leastNegative;
        }
    }
    //if control reaches here, there is at least one positive number
    while(arr[right] < 0)
    {
        right--;
    }


    int i, j;
    int leftSum = 0;
    int rightSum = 0;
    //from left, sum until sum is negative
    for(i=left; i<=right; i++)
    {
        leftSum = leftSum + arr[i];
        if(leftSum < 0)
            break;
    }

    //from right, sum until sum is negative
    for(j=right; j>=left; j--)
    {
        rightSum = rightSum + arr[j];
        if(rightSum < 0)
            break;
    }

    //if neither left nor right sum ever turned negative, return the sum (here left sum = right sum)
    if(i == right+1 && j == left-1)
        return leftSum;


    //split array at the last number summed (necessarily negative) from each direction
    //there are now either two or three (not necessarily disjoint) pieces of the array
    //recursively call routine on each piece
    int leftPart, rightPart, midPart, contender;

    if(i == right+1)    //if this is true, then j >= left
    {
        leftPart = largestSubArray(arr, left, j);
        rightPart = largestSubArray(arr, j, right);

        //find larger of leftPart and rightPart
        if(leftPart > rightPart)
            return leftPart;
        else
            return rightPart;
    }
    else if(j == left-1)    //if this is true, then i <= right
    {
        leftPart = largestSubArray(arr, left, i);
        rightPart = largestSubArray(arr, i, right);

        //find larger of leftPart and rightPart
        if(leftPart > rightPart)
            return leftPart;
        else
            return rightPart;
    }
    else
    {
        leftPart = largestSubArray(arr, left, i);
        rightPart = largestSubArray(arr, j, right);

        //find larger of leftPart and rightPart
        if(leftPart > rightPart)
            contender = leftPart;
        else
            contender = rightPart;

        if(i < j-1)     //if there is an index between i and j and i is lower
            midPart = largestSubArray(arr, i+1, j-1);
        else if(j < i-1)    //if there is an index between i and j and j is lower
            midPart = largestSubArray(arr, j+1, i-1);
        else
            return contender;       //if i and j were the same or adjacent indices, there is no midPart
    }

    //return largest sum of the two/three
    if(contender > midPart)
        return contender;
    else
        return midPart;

}
