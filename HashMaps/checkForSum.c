#include "main.h"

int checkForSum(int* arr, int N, int X)
{
    //create new hash table
    struct hMap* m = newHashMap(32);

    //put all elements of array into hash table
    int i;
    for(i=0; i<N; i++)
    {
        hashInsert(arr[i], m, arr[i]);
    }

    //check for sum
    for(i=0; i<N; i++)
    {
        int diff = X - arr[i];  //number that needs to be an element of array for the sum X to be present

        int tableIndex = hashFn(diff, m->N)%m->N;
        struct hMapEntry* entry = &(m->table[tableIndex]);

        //a flag to indicate, when 1, that we must look for a duplicate, because X = arr[i]*2
        int skipOne = 0;
        if(diff == arr[i])
            skipOne = 1;

        while(entry->next)  //check for collisions
        {
            if(entry->key == diff)
            {
                if(skipOne)
                    skipOne = 0;
                else
                    return 1;
            }
            entry = entry->next;
        }
    }

    return 0;
}
