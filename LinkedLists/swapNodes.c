#include "main.h"

void swapNodes(struct node** head, int key1, int key2)
{
    struct node* key1Node = 0;      //to hold addresses of nodes with key values
    struct node* key2Node = 0;

    struct node* key1Prev = 0;      //to hold addresses of preceding nodes
    struct node* key2Prev = 0;

    struct node* prev = 0;
    struct node* n = *head;
    while(n)    //stop if n == NULL
    {
        if((*n).val == key1 && !key1Node)       //if key1 was found for the first time
        {
            key1Node = n;
            key1Prev = prev;
        }
        else if((*n).val == key2 && !key2Node)  //if key2 was found for the first time
        {
            key2Node = n;
            key2Prev = prev;
        }

        prev = n;
        n = (*n).next;
    }

    if(key1Node && key2Node)    //if both values were found
    {
        if(key1Node == key2Prev)    //if key1 immediately preceded key2
        {
            (*key1Node).next = (*key2Node).next;
            (*key2Node).next = key1Node;
        }
        else if(key2Node == key1Prev)   //if key2 immediately preceded key1
        {
            (*key2Node).next = (*key1Node).next;
            (*key1Node).next = key2Node;
        }
        else
        {
            //switch nodes' next addresses
            struct node* tmp = (*key1Node).next;
            (*key1Node).next = (*key2Node).next;
            (*key2Node).next = tmp;
        }

        //switch prevs' next addresses
        if(key2Prev && key2Prev != key1Node)
        {
            (*key2Prev).next = key1Node;
        }
        if(key1Prev && key1Prev != key2Node)
        {
            (*key1Prev).next = key2Node;
        }

        if(!key1Prev)  //if key1 was in the head
        {
            *head = key2Node;           //let key2Node be the new head
        }
        else if(!key2Prev) //else if key2 was in the head
        {
            *head = key1Node;       //let key1Node be the new head
        }
    }
}
