#include "main.h"
#include <stdio.h>

void unionAndIntersection(struct listNode* list1, struct listNode* list2)
{
    struct listNode* unionList = 0;
    struct listNode* intersectionList = 0;

    struct hMap* m = newHashMap(32);        //create new hash map

    //add all unique elements of list1 to hash table and union list
    struct listNode* node = list1;
    while(node)
    {
        int tableIndex = hashFn(node->data, m->N)%m->N;
        struct hMapEntry* entry = &(m->table[tableIndex]);

        if(entry->next == 0)    //if this element hasn't been added to the table yet
        {
            hashInsert(1, m, node->data);   //add to the table
            append2List(&unionList, node->data);    //add to union list
        }

        node = node->next;  //go to next element in list1
    }

    //loop through list2
    node = list2;
    while(node)
    {
        int tableIndex = hashFn(node->data, m->N)%m->N;
        struct hMapEntry* entry = &(m->table[tableIndex]);

        int found = 0;
        while(entry)
        {
            if(entry->hashInput == node->data) //if an element of list2 is already in the table,
            {
                if(entry->key == 1) //if it was from list1 and not just a previous, duplicate element of list2
                {
                    append2List(&intersectionList, node->data); //add element to intersection list
                }
                found = 1;  //raise flag that we found a match
                break;  //break out of this while(entry) loop to go to next element in list2
            }
            entry = entry->next;
        }
        if(found == 0)  //if this element was not already in the table,
        {
            hashInsert(2, m, node->data);   //add to hash table
            append2List(&unionList, node->data);    //add to union list
        }

        node = node->next;
    }

    printCircularList(unionList);
    printCircularList(intersectionList);
}
