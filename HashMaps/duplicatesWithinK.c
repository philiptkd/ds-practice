#include "main.h"
#include <stdlib.h>

int duplicatesWithinK(int* arr, int N, int k)
{
    //create hash table
    struct hMap* m = newHashMap(32);

    //hash all elements of array into table
    int i;
    for(i=0; i<N; i++)
    {
        hashInsert(i, m, arr[i]);
    }

    //check for duplicates within k
    for(i=0; i<N; i++)
    {
        int tableIndex = hashFn(arr[i], m->N)%m->N;
        struct hMapEntry* entry = &(m->table[tableIndex]);

        while(entry->next)  //for every element in this bucket of the hash table
        {
            if(entry->key != i && abs(entry->key - i) <= k)     //if it's a duplicate of arr[i] within k in arr
            {
                return 1;
            }
            entry = entry->next;
        }
    }

    return 0;
}
