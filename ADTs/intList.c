#include "intList.h"
#include <stdlib.h>
#include <stdio.h>

struct intListType
{
    int key;
    struct intListType *next;
};

//constructs new list by appending to the front
intListPtr cons(int X, intListPtr oldList)
{
    intListPtr newFront = (intListPtr)malloc(sizeof(struct intListType));
    newFront->key = X;
    newFront->next = oldList;

    return (intListPtr)newFront;
}

//get first
int first(intListPtr aList)
{
    return aList->key;
}

//get rest of list
intListPtr rest(intListPtr aList)
{
    return aList->next;
}

//print list
void printIntList(intListPtr aList)
{
    intListPtr node = aList;

    while(node)
    {
        printf("%d ", node->key);
        node = node->next;
    }
    printf("\n");
}
