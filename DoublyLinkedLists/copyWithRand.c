#include "main.h"
#include <stdlib.h>

//copies a list with standard next pointers but random prev pointers
    //in O(n) time and O(1) extra space
struct doubleNode* copyWithRand(struct doubleNode* origHead)
{
    //can't point to something that doesn't exist
    struct doubleNode* newHead = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    struct doubleNode* n = origHead;
    struct doubleNode* m = newHead;

    //can't point to something that doesn't exist
    //create copies of all nodes and their next pointers
    //to use O(1) EXTRA space, we make use of the space already provided
    //uses original list's "next" pointers to map between lists
            //and original "val" space to restore the original list after copying
    do
    {
        struct doubleNode* nNext = (*n).next;
        (*m).val = (*n).val;                    //copies value
        (*n).val = (int)nNext;               //stores next node in data section
        (*n).next = m;                          //lets each original node point to its copied counterpart

        if(nNext)    //if there is a next node in the original list
        {
            struct doubleNode* nextM = (struct doubleNode*)malloc(sizeof(struct doubleNode));   //create next node

            (*m).next = nextM;      //set "next" pointer
            m = nextM;              //go to next copied node
        }
        else
        {
            (*m).next = 0;          //if there was not a "next" node in the original list, then there shouldn't be in the copied one, either
        }

        n = nNext;      //go to next original node
    }while(n);

    n = origHead;
    m = newHead;
    //copy "prev" pointers
    while(m)    //for every node in the copied list
    {
        struct doubleNode* nPrev = (*n).prev;
        if(nPrev)
        {
            (*m).prev = (*nPrev).next;          //get copied list's "prev" pointers through the mapping stored in original list's "next" pointers
        }
        else        //if the original node points to NULL, then the copied one should, too
        {
            (*m).prev = 0;
        }
        m = (*m).next;
        n = (struct doubleNode*)(*n).val;       //go to "next" node
    }

    n = origHead;
    m = newHead;
    //restore data section and "next" pointers of original nodes
    while(m)    //condition using m because the original list doesn't currently end with a NULL pointer
    {
        (*n).next = (struct doubleNode*)(*n).val;   //restore original "next" pointer
        (*n).val = (*m).val;                        //restore original val

        m = (*m).next;
        n = (*n).next;          //this is safe to do again, as we just reset it
    }

    return newHead;
}
