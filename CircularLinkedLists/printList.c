#include "main.h"
#include <stdio.h>

//prints a circular singly linked list
void printList(struct node* head)
{
    struct node* n = head;
    do
    {
        printf("%d ",(*n).val);
        n = (*n).next;
    }while(n != head);
    printf("\n");
}
