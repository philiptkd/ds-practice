#include "main.h"

//splits one circular linked list into two
//stores two new heads in "ret"
void split(struct node* head, struct node** ret)
{
    struct node* tail = head;
    struct node* mid = head;

    //find tail and mid
    while((*tail).next != head)
    {
        tail = (*tail).next;
        if((*tail).next != head)
        {
            tail = (*tail).next;
            mid = (*mid).next;
        }
    }

    struct node* secondHalf = (*mid).next;      //store the address of the start of the second half of the list
    (*mid).next = head;                         //point mid back to head, forming the first loop
    (*tail).next = secondHalf;                  //point tail back to the start of the second loop

    ret[0] = head;
    ret[1] = secondHalf;
}
