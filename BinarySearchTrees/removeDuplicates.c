#include "main.h"
#include <stdlib.h>

//removes duplicate elements in a sorted doubly-linked list
//the second of a duplicate pair is always deleted, so the head of the list is never changed
void removeDuplicates(struct listNode* head)
{
    if(head == 0)       //no duplicates in an empty list
        return;

    struct listNode* prev = head;  //store first item in list
    head = head->next;

    while(head)
    {
        if(head->data == prev->data)  //if we've found a duplicate
        {
            struct listNode* headNext = head->next; //save for next loop

            if(!head->next) //if this is the last node
            {
                prev->next = 0;     //make prev the last node
                free(head);             //free the memory for the deleted node
            }
            else    //if this is not the last node
            {
                prev->next = head->next;
                head->next->prev = prev;
                free(head);             //free the memory for the deleted node
            }

            head = headNext;
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
}
