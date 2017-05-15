#include "main.h"
#include <stdlib.h>

//given the first node of a list, delete the first node having "val" value
void deleteFirstOccurrence(struct node** head, int toFind)
{
    //check the head
    if((**head).val == toFind)
    {
        struct node* tmp = (**head).next;  //save second node's address
        free(*head);
        *head = tmp;    //point "head" to second node
        return;
    }

    //check the rest
    struct node* i = *head;
    while((*i).next)    //stop if we reach a NULL pointer
    {
        struct node* prev = i;  //store previous node's address
        i = (*i).next;      //move to next node
        if((*i).val == toFind)  //check its value
        {
            (*prev).next = (*i).next;   //point over node at address i
            free(i);    //free memory
            return;
        }
    }
}
