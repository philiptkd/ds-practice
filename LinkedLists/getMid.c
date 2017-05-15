#include "main.h"
int getMid(struct node* head)
{
    //count nodes in list
    int count = 0;
    struct node* n = head;
    while(n)
    {
        count++;
        n = (*n).next;
    }

    //go to middle node. if count is even, goes to second middle node
    int i;
    for(i=0; i<count/2; i++)
    {
        head = (*head).next;
    }

    return (*head).val;
}
