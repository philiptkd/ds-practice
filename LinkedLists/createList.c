#include <stdlib.h>
#include "main.h"

struct node* createList()
{
    //creating pointers to nodes of the list
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    //assigning memory in the heap for each node and returning the addresses
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //can access parts of structs like this
    (*head).val = 1;
    (*head).next = second;

    //or like this
    second->val = 2;
    second->next = third;

    //end the list with a null pointer
    (*third).val = 3;
    (*third).next = NULL;

    return head;
}
