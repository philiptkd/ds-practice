#include "main.h"
#include <stdlib.h>

//deletes the pos'th node
//counts from 0
void deleteAtPos(struct node** head, int pos)
{
    //if we need to delete the head
    if(pos == 0)
    {
        struct node* tmp = (**head).next;   //save address of second node
        free(*head);    //free memory
        *head = tmp;        //set second node as new head
        return;
    }

    int i;
    struct node* thisPos = *head;
    for(i=0; i<pos-1; i++)          //find the node pointing to the one we want to delete
    {
        if(thisPos == NULL)     //stop if the list is not long enough
            return;
        thisPos = (*thisPos).next;      //go to next node
    }

    struct node* prev = thisPos;

    if(thisPos == NULL || (*thisPos).next == NULL)     //stop if the list is not long enough
        return;

    thisPos = (*thisPos).next;          //give "thisPos" the address of the node to be deleted
    (*prev).next = (*thisPos).next;     //point "prev" node over node to be deleted
    free(thisPos);      //free memory
}
