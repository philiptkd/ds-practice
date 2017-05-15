#include "main.h"
#include <stdio.h>

int main()
{
    int N = 6;
    int k = 3;
    int arr[6] = {2, 6, 3, 12, 56, 8};

    sortNearlySorted((int*)arr, N, k);

    int i=0;
    for(i=0; i<N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
