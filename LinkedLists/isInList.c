#include "main.h"
#include <stdio.h>

//returns 1 if toFind is in the list. otherwise, returns 0
int isInList(struct node* n, int toFind)
{
    if(!n)       //stop if reach NULL pointer
        return 0;

    if((*n).val == toFind)
        return 1;

    return isInList((*n).next, toFind);
}
