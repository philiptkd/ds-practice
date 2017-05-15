#include "main.h"
#include <stdlib.h>

void deleteAtPos(struct doubleNode** head, int pos)
{
    //if deleting the head
    if(pos == 0)
    {
        struct doubleNode* newHead = (**head).next;
        (*newHead).prev = 0;

        free(*head);        //free memory allocated for the node
        *head = newHead;    //make 2nd node the new head
        return;
    }

    //get to the node to be deleted
    struct doubleNode* n = *head;
    int i;
    for(i=0; i<pos; i++)
    {
        if((*n).next)
        {
            n = (*n).next;
        }
        else                    //if pos is at least the length of the list don't do anything
        {
            return;
        }
    }

    //if we're deleting the last node
    if((*n).next == 0)
    {
        (*(*n).prev).next = 0;
        free(n);
    }
    else
    {
        (*(*n).prev).next = (*n).next;  //point prev to next
        (*(*n).next).prev = (*n).prev;  //point next to prev
        free(n);
    }
}
