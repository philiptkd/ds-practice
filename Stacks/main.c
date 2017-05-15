#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int* nextSmaller(int* arr, int N);
int* prevSmaller(int* arr, int N);
int* highestLocalMin(int* data, int N);

int main()
{
    int data[7] = {10, 20, 30, 50, 10, 70, 30};
    int* ans = highestLocalMin(data, 7);

    int i;
    for(i=0; i<7; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}

