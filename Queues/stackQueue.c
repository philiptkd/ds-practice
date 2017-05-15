//implements a queue using stacks

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

struct stackQ* createStackQ()
{
    struct stackQ* sq = (struct stackQ*)malloc(sizeof(struct stackQ));     //allocate memory for metadata
    (*sq).first = 0;        //initialize pointers
    (*sq).rest = 0;

    return sq;
}

int sqIsEmpty(struct stackQ* sq)
{
    struct stackNode* first = (*sq).first;

    if(first)           //if there is an element in first stack, the queue is not empty
        return 0;
    else                    //if first stack is empty, rest stack is empty
        return 1;
}

void sqEnqueue(struct stackQ* sq, int data)
{
    if(sqIsEmpty(sq))      //if first stack is empty, rest stack must also be empty. this is the first value to be enqueued
    {
        push(&(sq->first), data);
    }
    else        //if first stack is not empty, this is not the first value to be enqueued
    {
        push(&(sq->rest), data);
    }
}

int sqDequeue(struct stackQ* sq)
{
    if(sqIsEmpty(sq))       //do nothing if the queue is empty
        return -1;

    int ret = (sq->first)->data;            //save value to return, the first value enqueued
    free(sq->first);                //free memory
    sq->first = 0;                  //rename first to indicate it is empty

    if(!sq->rest)           //if rest stack is empty, there is nothing to do
    {
        //do nothing
    }
    else
    {
        while((sq->rest)->next)     //while there is more than one element on rest stack
        {
            push(&(sq->first), pop(&(sq->rest)));       //temporarily transfer elements from rest to first, upside down
            //the "rest" pointer is updated within pop()
        }
        int bottom = pop(&(sq->rest));        //pop the last element of rest into a temporary variable

        while((sq->first))        //while there is an element on first stack
        {
            push(&(sq->rest), pop(&(sq->first)));       //put them all back on first stack, right side up
            //the "first" pointer is updated within pop()
        }

        push(&(sq->first), bottom);       //put what was the bottom of rest stack onto the now empty first stack
    }

    return ret;
}

int sqFrontVal(struct stackQ* sq)
{
    if(sqIsEmpty(sq))
        return -1;

    return peek(sq->first);
}

int sqBackVal(struct stackQ* sq)
{
    if(sqIsEmpty(sq))
        return -1;

    if(sq->rest)                        //if the queue has more than one element, the back will be in rest stack
        return peek(sq->rest);
    else                            //if the queue has only one element, the back will be in first stack
        return peek(sq->first);
}

void printSQ(struct stackQ* sq)
{
    printStack(sq->rest);
    printStack(sq->first);
    printf("\n");
}
