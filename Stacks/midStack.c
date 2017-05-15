//implements a stack with a doubly linked list and the functionality to find and delete the middle element in O(1) time_base

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

struct midStack* createEmptyMidStack()      //creates an empty stack that is safe to push to
{
    struct midStack* ret = (struct midStack*)malloc(sizeof(struct midStack));
    (*ret).parity = 0;
    (*ret).top = 0;
    (*ret).mid = 0;

    return ret;
}

int midIsEmpty(struct midStack* mStack)
{
    if((*mStack).top)
        return 0;
    else
        return 1;
}

void midPush(struct midStack* mStack, int data)
{
    (*mStack).parity = (*mStack).parity ^ 1;        //keeps track of the parity of the number of elements in the stack

    struct midStackNode* newTop = (struct midStackNode*)malloc(sizeof(struct midStackNode));
    (*newTop).data = data;
    (*newTop).up = 0;   //there is no node above the new top node

    if(midIsEmpty(mStack))      //if the stack was empty
    {
        (*newTop).down = 0;             //there is no element below the new top
        (*mStack).top = newTop;         //rename top
        (*mStack).mid = newTop;         //top is also mid for a stack with a single element
    }
    else            //if the stack was not empty
    {
        struct midStackNode* oldTop = (*mStack).top;
        (*newTop).down = oldTop;            //set pointers within the stack
        (*oldTop).up = newTop;
        (*mStack).top = newTop;             //rename top
        if((*mStack).parity)                //rename mid if there is now an odd number of elements
        {
            (*mStack).mid = (*(*mStack).mid).up;
        }
    }
}

//because we have isEmpty(), assumes not empty
int midPop(struct midStack* mStack)
{
    int ret;
    (*mStack).parity = (*mStack).parity ^ 1;        //keeps track of the parity of the number of elements in the stack

    struct midStackNode* oldTop = (*mStack).top;
    if((*oldTop).down == 0)                     //if there is only one element in the stack
    {
        ret = (*oldTop).data;               //value to return
        (*mStack).top = 0;                    //rename top
        (*mStack).mid = 0;                    //rename mid
        free(oldTop);                           //free the memory
    }
    else                        //else if there is more than one element in the stack
    {
        struct midStackNode* newTop = (*oldTop).down;
        ret = (*oldTop).data;                   //value to return
        (*newTop).up = 0;                           //set newTop's pointers
        (*mStack).top = newTop;                     //rename top
        if(!(*mStack).parity)                       //if the number of elements in the stack is now even
        {
            (*mStack).mid = (*(*mStack).mid).down;      //rename mid
        }
        free(oldTop);                               //free the memory
    }
    return ret;
}

int midPeek(struct midStack* mStack)
{
    struct midStackNode* top = (*mStack).top;
    return (*top).data;
}

int getMid(struct midStack* mStack)
{
    return (mStack->mid)->data;
}

//because we choose the lower option for mid when we have a choice, mid and top are only equal when the stack has only one element
void deleteMid(struct midStack* mStack)
{
    (*mStack).parity = (*mStack).parity ^ 1;    //flip the parity

    if((*mStack).mid == (*mStack).top)      //if there is only one element in the stack
    {
        free((*mStack).mid);                //free the memory
        (*mStack).mid = 0;                  //reset pointers to zero for an empty stack
        (*mStack).top = 0;
    }
    else
    {
        struct midStackNode* oldMid = (*mStack).mid;
        if((*mStack).parity)                       //if the number of elements in the stack is now odd
        {
            (*mStack).mid = (*oldMid).up;      //rename mid
        }
        else                                        //if the number of elements in the stack is now even
        {
            (*mStack).mid = (*oldMid).down;      //rename mid
        }

        (oldMid->up)->down = oldMid->down;      //let the node above the old mid point to the one below the old mid

        if(oldMid->down)        //sometimes the mid is the bottom element of the stack, in which case, it has no element below it
        {
            (oldMid->down)->up = oldMid->up;        //let the node below the old mid point to the one above the old mid
        }

        free(oldMid);
    }
}

void printMidStack(struct midStack* mStack)
{
    struct midStackNode* n = (*mStack).top;
    while(n)
    {
        printf("%d ", (*n).data);
        n = (*n).down;
    }
    printf("\n");
}
