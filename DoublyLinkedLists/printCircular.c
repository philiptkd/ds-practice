#include "main.h"
#include <stdio.h>

//prints a circular doubly linked list
    //forwards and backwards to test all pointers
void printCircular(struct doubleNode* head)
{
    struct doubleNode* n = head;

    //print forward
    do
    {
        printf("%d ",(*n).val);
        n = (*n).next;
    }while(n != head);
    printf("\n");

    //print backward
    do
    {
        n = (*n).prev;
        printf("%d ",(*n).val);
    }while(n != head);
}
