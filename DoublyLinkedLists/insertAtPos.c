#include "main.h"
#include <stdlib.h>

void insertAtPos(struct doubleNode** head, int pos, int toInsertVal)
{
    //create node
    struct doubleNode* toInsert = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    (*toInsert).val = toInsertVal;

    //if adding to the front
    if(pos == 0)
    {
        //set toInsert's pointers
        (*toInsert).prev = 0;
        (*toInsert).next = *head;

        (**head).prev = toInsert;   //set next's pointers
        *head = toInsert;       //make toInsert the new head
        return;
    }

    //if control reaches here, pos > 0
    struct doubleNode* n = *head;

    //get to position of new node
    int putAtEnd = 0;
    int i;
    for(i=0; i<pos; i++)
    {
        if((*n).next)
        {
            n = (*n).next;
        }
        else                    //if pos is at least the length of the list, add toInsert to the end
        {
            putAtEnd = 1;
        }
    }

    //if toInsert is last
    if(putAtEnd)
    {
        //set toInsert's pointers
        (*toInsert).prev = n;
        (*toInsert).next = 0;

        (*n).next = toInsert;   //set prev's pointers
    }
    else
    {
        //set toInsert's pointers
        (*toInsert).prev = (*n).prev;
        (*toInsert).next = n;

        (*(*n).prev).next = toInsert;    //set prev's pointers
        (*n).prev = toInsert;            //set next's pointers
    }
}
