#include "main.h"
#include <stdlib.h>

//inserts a value X into a sorted circular linked list
void sortedInsert(struct node** head, int X)
{
    struct node* toInsert = (struct node*)malloc(sizeof(struct node));  //allocate memory for the new node
    (*toInsert).val = X;        //set value of new node

    //if less than head
    if(X < (**head).val)
    {
        (*toInsert).next = *head;       //point new node to old head

        struct node* last = *head;
        while((*last).next != *head)    //find the end of the list
        {
            last = (*last).next;
        }

        (*last).next = toInsert;        //let the last node now point to the new node
        *head = toInsert;               //let "*head" now refer to the new node's address

        return;
    }

    //else
    struct node* insertAfter = *head;
    while((*insertAfter).next != *head)
    {
        struct node* insertBefore = (*insertAfter).next;
        if(X < (*insertBefore).val)
        {
            (*insertAfter).next = toInsert;
            (*toInsert).next = insertBefore;

            return;
        }
        insertAfter = (*insertAfter).next;
    }

    //if control reaches here, X is larger than every value in the list
    (*insertAfter).next = toInsert;
    (*toInsert).next = *head;
}
