#include "main.h"

void reverse(struct node** head)
{
    struct node* n = *head;
    struct node* prev = 0;

    while(n)
    {
        struct node* tmp = (*n).next;

        (*n).next = prev;       //point current node backwards
        prev = n;               //move "previous" node down the list
        n = tmp;                //move current node down the list
    }

    *head = prev;       //set last node as new head
}
