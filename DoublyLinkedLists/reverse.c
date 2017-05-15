#include "main.h"

//reverses a doubly linked list by swapping the next and prev pointers for each node
void reverse(struct doubleNode** head)
{
    struct doubleNode* tmp;

    //swap first node's pointers
    tmp = (**head).prev;
    (**head).prev = (**head).next;
    (**head).next = tmp;

    //swap the rest
    struct doubleNode* n = *head;
    while((*n).prev)                //the new "prev" is the old "next"
    {
        n = (*n).prev;          //go to next node

        tmp = (*n).prev;
        (*n).prev = (*n).next;
        (*n).next = tmp;
    }

    //make the last node the new head
    *head = n;
}
