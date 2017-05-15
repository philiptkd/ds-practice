#include <stdlib.h>
#include "main.h"

//creates an array of addresses for the nodes of the linked list
struct node* createBiggerList()
{
    int len = 5;
    struct node* addrArr[len];

    int i;
    for(i=0; i<len; i++)
    {
        addrArr[i] = (struct node*)malloc(sizeof(struct node));
        (*addrArr[i]).val = i;
        (*addrArr[i]).next = 0;

        if(i)
        {
            (*addrArr[i-1]).next = addrArr[i];
        }
    }

    return addrArr[0];
}
