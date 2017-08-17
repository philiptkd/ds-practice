#include "main.h"
#include <stdio.h>

//prints a circular (doubly) linked list
void printCircularList(struct listNode* head)
{
    struct listNode* n = head;
    do
    {
        printf("%d ",(*n).data);
        n = (*n).next;
    }while(n != head);
    printf("\n");
}
