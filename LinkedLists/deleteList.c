#include "main.h"
#include <stdlib.h>

//deletes a singly linked list by calling free() on each node
void deleteList(struct node* head)
{
    while(head)
    {
        struct node* tmp = head;
        head = (*head).next;
        free(tmp);
    }
}
