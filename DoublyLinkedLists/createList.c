#include "main.h"
#include <stdlib.h>

struct doubleNode* createList()
{
    int len = 10;
    struct doubleNode* addrArr[len];

    int i;
    for(i=0; i<len; i++)
    {
        addrArr[i] = (struct doubleNode*)malloc(sizeof(struct doubleNode));
        (*addrArr[i]).next = 0;
        (*addrArr[i]).prev = 0;
        (*addrArr[i]).val = len-i;

        if(i)
        {
            (*addrArr[i-1]).next = addrArr[i];
            (*addrArr[i]).prev = addrArr[i-1];
        }
    }
    (*addrArr[0]).next = addrArr[1];

    return addrArr[0];
}
