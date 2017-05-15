#include <stdlib.h>
#include "main.h"

//adds a new node to the front of a linked list
//head address passed by reference so we can change it
void push(struct node** oldHead, int newHeadVal)
{
    struct node* newHead = (struct node*)malloc(sizeof(struct node));   //allocate memory for new node
    (*newHead).val = newHeadVal;    //set value
    (*newHead).next = *oldHead;     //let newHead point to oldHead

    *oldHead = newHead;             //set newHead's address as the new starting address held in *oldHead
}
