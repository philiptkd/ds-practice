//this file contains functions for a queue that operates on structs that hold two ints

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void enqueue2(struct tupleQNode** back, int i, int j)
{
    struct tupleQNode* newBack = (struct tupleQNode*)malloc(sizeof(struct tupleQNode));   //allocate memory for new node
    (*newBack).i = i;
    (*newBack).j = j;

    if(*back)    //if the queue was not empty
    {
        struct tupleQNode* front = (**back).prev;     //the front is the last node of the list

        (*newBack).prev = front;        //set new node's pointers
        (*newBack).next = *back;
        (*front).next = newBack;        //reset old nodes' pointers
        (**back).prev = newBack;
    }

    else    //if the queue was empty
    {
        (*newBack).prev = newBack;
        (*newBack).next = newBack;
    }

    *back = newBack;                //rename back

}

struct tuple* dequeue2(struct tupleQNode** back)
{
    struct tupleQNode* front = (**back).prev;        //the front is the last node of the list
    struct tuple* ret = (struct tuple*)malloc(sizeof(struct tuple));
    ret->i = (*front).i;                        //the value to be returned
    ret->j = (*front).j;

    if(front == *back)        //if the queue had only one node
    {
        *back = 0;
    }
    else
    {
        struct tupleQNode* newFront = (*front).prev;     //the new front node after this one is dequeued
        (*newFront).next = *back;                       //reset pointers
        (**back).prev = newFront;
    }

    free(front);                                    //free memory for front node
    return ret;
}

struct tuple* frontVal2(struct tupleQNode* back)
{
    struct tupleQNode* front = back->prev;
    struct tuple* ret = (struct tuple*)malloc(sizeof(struct tuple));
    ret->i = front->i;
    ret->j = front->j;

    return ret;
}

struct tuple* backVal2(struct tupleQNode* back)
{
    struct tuple* ret = (struct tuple*)malloc(sizeof(struct tuple));
    ret->i = back->i;
    ret->j = back->j;

    return ret;
}

int isEmpty2(struct tupleQNode* back)
{
    if(back)
        return 0;       //queue is not empty if the back element has an address
    else
        return 1;
}

void printQueue2(struct tupleQNode* back)
{
    if(!back)                   //stop if the queue is empty
        return;

    printf("(%d, %d) ", (*back).i, (*back).j);        //print the first value

    struct tupleQNode* qn = back;
    while((*qn).next && (*qn).next != back)
    {
        qn = (*qn).next;
        printf("(%d, %d) ", (*qn).i, (*qn).j);
    }
    printf("\n");
}
