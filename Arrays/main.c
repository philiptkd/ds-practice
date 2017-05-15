#include <stdio.h>

void countInversions(int arr[], int arrWorking[], int start, int end, int depth, int* count);

int main()
{
    int arr[5] = {2, 4, 1, 3, 5};
    int arrWorking[5];
    int i;
    for(i=0; i<5; i++)
    {
        arrWorking[i] = arr[i];
    }

    int count = 0;
    countInversions(arr, arrWorking, 0, 4, 0, &count);
    printf("%d", count);
    return 0;
}
