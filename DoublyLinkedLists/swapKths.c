#include "main.h"

void swap(struct doubleNode* n, struct doubleNode* m);

//swaps the Kth node from the front with the Kth node from the end
void swapKths(struct doubleNode** head, int K)
{
    struct doubleNode* fromFront = *head;
    struct doubleNode* fromBack;

    //find the Kth node from the head
    int i;
    for(i=0; i<K; i++)
    {
        if((*fromFront).next)
        {
            fromFront = (*fromFront).next;
        }
        else
        {
            return;         //if there are not at least K+1 nodes in the list, return the list unchanged
        }
    }

    //find the tail
    fromBack = fromFront;
    while((*fromBack).next)
    {
        fromBack = (*fromBack).next;
    }

    //find the Kth node from the tail
    for(i=0; i<K; i++)
    {
        fromBack = (*fromBack).prev;        //because we found fromFront, we know there are at least K+1 nodes in the list
    }

    swap(fromFront, fromBack);      //swap the two nodes by changing pointers

    //make sure "head" points to the new start of the list, if it changed
    if(fromFront == *head)
    {
        *head = fromBack;
    }
    else if(fromBack == *head)
    {
        *head = fromFront;
    }
}
