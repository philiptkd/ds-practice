#include "main.h"

//given two arrays and their lengths,
//returns whether all elements in arr2 are also in arr1
int isArrSubset(int* arr1, int N1, int* arr2, int N2)
{
    //create hash table
    struct hMap* m = newHashMap(32);

    //put elements of arr1 into the hash table
    int i;
    for(i=0; i<N1; i++)
    {
        hashInsert(arr1[i], m, arr1[i]);        //here, the data we're storing is also the input to the hash function
    }

    //check if all elements of arr2 are now in the hash table
    for(i=0; i<N2; i++)
    {
        int found = 0;
        int tableIndex = hashFn(arr2[i], m->N)%m->N;        //get index of where this element of arr2 would be placed into the table
        struct hMapEntry* entry = &(m->table[tableIndex]);  //get pointer to table entry

        while(entry->next)  //for every item in list that starts at this index of the table
        {
            if(entry->key == arr2[i])   //if this element of arr2 was found in the table
            {
                found = 1;      //raise flag
                break;          //break out of the while loop to move on to the next element of arr2
            }
        }

        if(found == 0)  //if it wasn't found
            return 0;       //there is an element of arr2 that's not in arr1
    }

    return 1;
}
