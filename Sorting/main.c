#include "main.h"
#include <stdio.h>

int main()
{
    int A[] = {9,  4,  2,  5,  0,  3,  6,  8,  7,  1};
    int len = sizeof(A)/sizeof(int);
    shellSort((int*)A, len);

    //print
    int i;
    for(i=0; i<len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
