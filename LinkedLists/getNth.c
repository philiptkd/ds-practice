#include "main.h"

//returns the data value of the Nth node in the list
int getNth(struct node* head, int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(!head)       //if we reach a null pointer
            return -1;

        head = (*head).next;        //head address was passed by value, so we don't risk changing it outside of this scope
    }

    return (*head).val;
}
