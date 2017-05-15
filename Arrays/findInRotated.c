//finds an element X in a sorted but rotated array
//the idea is to visualize the array as a circle instead of a line segment
//arr[] : the array to be searched
//N : the length of the array
//X : the number to find

#include <math.h>

int findInRotated(int arr[], int N, int X)
{
    int prev = 1;
    int next = 0;   //to ensure the first evaluation of the while condition goes as expected
    int i = 1;
    int dir = 1;

    //check endpoint
    if(arr[prev] == X)
        return prev;

    while(prev != next)
    {
        prev = next;
        if(arr[prev] > X)    //if too big, typically go ccw
        {
            next = ((int)(prev - ceil(N/pow(2,i))*dir))%N;     //the remainder operator could still give us a negative result
            while(next < 0){ next = next + N; } //ensures next is positive

            //check
            if(arr[next] == X)
                return next;

            if(arr[next] > arr[prev]*dir)  //going ccw, we'd expect values to go down, unless we passed the wrap point
            {
                dir = dir*(-1);
            }
        }
        else    //if too small, typically go cw
        {
            next = ((int)(prev + ceil(N/pow(2,i))*dir))%N;     //the mod N ensures we don't access outside the array

            //check
            if(arr[next] == X)
                return next;

            if(arr[next] < arr[prev]*dir)   //going cw, we'd expect values to go up, unless we passed the wrap point
            {
                dir = dir*(-1);
            }
        }

        i++;    //divide step size by 2
    }

    return -1;
}
