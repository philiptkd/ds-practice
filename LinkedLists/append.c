#include "main.h"
#include <stdlib.h>

void append(struct node* head, int toAppendVal)
{
    struct node* toAppend = (struct node*)malloc(sizeof(struct node));  //allocate memory for new last node
    (*toAppend).val = toAppendVal;
    (*toAppend).next = NULL;        //this is to be the new last node in the list

    while((*head).next)     //until we hit a null pointer
    {
        head = (*head).next;
    }

    //"head" in this scope now holds the address of the current last node in the list
    (*head).next = toAppend;    //point it to the new last node
}
