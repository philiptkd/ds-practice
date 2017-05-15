#include "main.h"
#include <stdio.h>

//prints the values of a linked list
void printList(struct node* n)
{
    while(n)     //while we have not reached a null pointer
    {
        printf("%d ", (*n).val);    //print the node's value
        n = (*n).next;      //point n to next node
    }
    printf("\n");
}
