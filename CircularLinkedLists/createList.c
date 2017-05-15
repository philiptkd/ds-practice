#include "main.h"
#include <stdlib.h>

//creates a circular singly linked list
struct node* createList()
{
    int len = 10;
    struct node* addrArr[len];

    int i;
    for(i=0; i<len; i++)
    {
        addrArr[i] = (struct node*)malloc(sizeof(struct node));           //allocate memory for each address
        (*addrArr[i]).val = i;

        if(i)
        {
            (*addrArr[i-1]).next = addrArr[i];          //once this memory has been allocated, point the previous node to it
        }
    }

    (*addrArr[len-1]).next = addrArr[0];        //point the last node towards the first

    return addrArr[0];
}
