#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 4};

    printf("%d", duplicatesWithinK((int*)arr, sizeof(arr)/sizeof(int), 3));

    return 0;
}
