#include "main.h"

//recursively counts the number of nodes in a list
int getLength(struct node* n)
{
    if(!n)      //stop if n is NULL
        return 0;

    return 1 + getLength((*n).next);
}
