#include "main.h"
#include <stdio.h>

//prints a doubly linked list forwards and backwards to test all pointers
void printList(struct doubleNode* head)
{
    //print forward
    printf("%d ", (*head).val);
    while((*head).next)         //stop at NULL
    {
        head = (*head).next;
        printf("%d ", (*head).val);
    }
    printf("\n");

    //print backward
    printf("%d ", (*head).val);
    while((*head).prev)
    {
        head = (*head).prev;
        printf("%d ", (*head).val);
    }
    printf("\n\n");
}
