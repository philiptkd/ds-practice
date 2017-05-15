#include "main.h"
#include <stdlib.h>

//inserts a new value into a linked list after a specified node
void insertAfter(struct node* refNode, int insertVal)
{
    struct node* toInsert = (struct node*)malloc(sizeof(struct node));  //allocate memory for new node
    (*toInsert).val = insertVal;       //set value
    (*toInsert).next = (*refNode).next;     //point to what refNode currently points to

    (*refNode).next = toInsert;     //point refNode to toInsert
}
