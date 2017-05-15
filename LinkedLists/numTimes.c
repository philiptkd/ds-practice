#include "main.h"

int numTimes(struct node* head, int X)
{
    int count = 0;
    while(head)
    {
        if((*head).val == X)
            count++;

        head = (*head).next;
    }
    return count;
}
