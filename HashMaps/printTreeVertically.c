#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//wrapper for recursive function with more parameters
void printTreeVertically(struct treeNode* root)
{
    //create hash table of a power of 2
    struct hMap* m = newHashMap(32);

    int minHorizDist = INT_MAX;
    int maxHorizDist = INT_MIN;

    //store tree in hash table
    printTreeVerticallyRecur(root, 0, m, &minHorizDist, &maxHorizDist);

    //print from hash table
    int d;
    for(d=minHorizDist; d<=maxHorizDist; d++)
    {
        int tableIndex = hashFn(d, m->N)%m->N;
        struct hMapEntry* slot = &(m->table[tableIndex]);
        while(slot->next)               //for every item in bucket
        {
            if(slot->hashInput == d)            //only print if stored hash input is equal to desired horizDist
                printf("%d ", slot->key);
            slot = slot->next;
        }
        printf("\n");
    }
}

//use preorder tree traversal to visit all nodes
//for each node, store its key in a hashmap
void printTreeVerticallyRecur(struct treeNode* root, int horizDist, struct hMap* m, int* minHorizDist, int* maxHorizDist)
{
    //update min and max horizontal distances for use in printing
    if(horizDist < *minHorizDist)
        *minHorizDist = horizDist;
    if(horizDist > *maxHorizDist)
        *maxHorizDist = horizDist;

    //put through hash function and store in table
    hashInsert(root->data, m, horizDist);

    //recur
    if(root->left)
        printTreeVerticallyRecur(root->left, horizDist-1, m, minHorizDist, maxHorizDist);
    if(root->right)
        printTreeVerticallyRecur(root->right, horizDist+1, m, minHorizDist, maxHorizDist);
}

void hashInsert(int key, struct hMap* m, int horizDist)
{
    //get index into hash map
    int i = hashFn(horizDist, m->N)%m->N;
    struct hMapEntry* slot = &(m->table[i]);

    //get to the first empty slot in the bucket
    while(slot->next)
    {
        slot = slot->next;
    }

    //store data and allocate memory for another entry in this bucket
    slot->key = key;
    slot->hashInput = horizDist;
    slot->next = (struct hMapEntry*)malloc(sizeof(struct hMapEntry));
    slot->next->next = 0;

    //increment m->numItems
    m->numItems = m->numItems + 1;

    //if numItems > N (table size), increase table size
    if(m->numItems > m->N)
    {
        int nextSize = m->N*2;
        m->N = nextSize;

        //create new table of size nextSize
        struct hMap* newMap = newHashMap(nextSize);

        //re-hash the original table into the new table and free the old table
        reHash(m, newMap);
    }
}

void deleteFromHashMap(int horizDist, struct hMap* m)
{
    int tableIndex = hashFn(horizDist, m->N)%m->N;

    struct hMapEntry* slot = &(m->table[tableIndex]);
    struct hMapEntry* prevSlot = 0;

    while(slot && slot->next)   //if this slot isn't empty
    {
        if(slot->hashInput == horizDist)    //check for correct horizDist in case of a previous collision
        {
            struct hMapEntry* nextSlot = slot->next;

            if(!prevSlot)       //if this is the first slot in the bucket
            {
                //copy data from next slot to the first slot
                slot->key = nextSlot->key;
                slot->hashInput = nextSlot->hashInput;
                slot->next = nextSlot->next;

                //delete next slot
                free(nextSlot);
            }
            else        //if it's not the first slot
            {
                prevSlot->next = slot->next;
                free(slot);
                slot = nextSlot;
            }

            m->numItems = m->numItems - 1;      //decrement number of items stored in table
        }
        else    //if it wasn't of the correct horizDist, go to the next one
        {
            prevSlot = slot;
            slot = slot->next;
        }
    }

    //if numItems < N/4, decrease table size (with a floor of 32)
    if(m->numItems < m->N / 4 && m->N/4 >= 32)
    {
        int nextSize = m->N/4;
        m->N = nextSize;

        //create new table of size nextSize
        struct hMap* newMap = newHashMap(nextSize);

        //re-hash the original table into the new table and free the old table
        reHash(m, newMap);
    }
}


struct hMap* newHashMap(int N)
{
    struct hMap* m = (struct hMap*)malloc(sizeof(struct hMap));     //allocate memory for map info
    m->N = N;   //size of table
    m->numItems = 0;    //number of items in the table
    m->table = (struct hMapEntry*)malloc(N*sizeof(struct hMapEntry));  //allocate memory for table

    int i;
    for(i=0; i<N; i++)          //initialize all next pointers to null
    {
        m->table[i].next = 0;
    }

    return m;
}

void reHash(struct hMap* oldMap, struct hMap* newMap)
{
    int i;
    for(i=0; i<oldMap->N; i++)          //for each index into the table
    {
        struct hMapEntry* entry = &(oldMap->table[i]);  //get the pointer to the front of the list at this index
        while(entry->next)    //as long as there is another item in the list
        {
            struct hMapEntry* nextEntry = entry->next;  //store pointer to next item in list

            hashInsert(entry->key, newMap, entry->hashInput);   //insert into the new table

            free(entry);    //free current item
            entry = nextEntry;    //go to next item in the list
        }
        free(entry);        //free the last item in the list
    }
    free(oldMap);       //free the container for the metadata
}

int hashFn(int input, int tableSize)
{
    //tableSize is assumed to be a power of 2
    int power = (int)log2(tableSize);   //tableSize = 2^power
    int bitsInAnInt = 8*sizeof(int);
    double randomLookingNum;

    //this to prevent collisions between numbers with the same absolute value
    if(input >= 0)
        randomLookingNum = (sqrt(5)-1)/2.0;
    else
        randomLookingNum = 3.141592653589793 - 3;

    unsigned int s = (unsigned int)(randomLookingNum * pow(2, bitsInAnInt));  //gets first (32) bits of randomLookingNum as an int
    unsigned int x = ((unsigned int)abs(input))*s;    //multiply by input
    int ret = (int)(x >> (bitsInAnInt - power));   //gets (power) most significant bits from x so it can fit in table

    return ret;
}
