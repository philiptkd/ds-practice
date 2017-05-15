#include "main.h"
#include <stdio.h>

//prints values of each node in a doubly linked list
    //as well as the values of the nodes each node points to
void printConnections(struct doubleNode* head)
{
    while(head)
    {
        int prev = -1;
        int next = -1;

        if((*head).prev)
        {
            prev = (*(*head).prev).val;
        }
        if((*head).next)
        {
            next = (*(*head).next).val;
        }

        printf("%d <- %d -> %d\n", prev, (*head).val, next);
        head = (*head).next;
    }
    printf("\n");
}
