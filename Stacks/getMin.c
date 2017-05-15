//this file contains an implementation of a stack with a getMin() function that returns the minimum element in a stack
//implemented with singly linked lists
//all functions run in O(1) time

//must allocate memory for two pointers within top level struct before pushing data

#include "main.h"

void getMinPush(struct getMinStack* top, int data)
{
    push(&((*top).dataStack), data);            //push data onto dataStack

    if(isEmpty((*top).minStack))                //if the stacks are empty, this value is by default the minimum
    {
        push(&((*top).minStack), data);         //push data onto minStack to store the minimum
    }
    else                                        //if they aren't empty, push onto minStack only if data <= current min
    {
        int min = peek((*top).minStack);
        if(data <= min)
        {
            push(&((*top).minStack), data);
        }
    }
}

int getMinPop(struct getMinStack* top)
{
    int popped = pop(&((*top).dataStack));                     //pop data off of dataStack
    if(popped == peek((*top).minStack))                     //if it is equal to the top of minStack, then they were pushed together
    {
        pop(&((*top).minStack));                               //pop off from the minStack to keep the min at the top
    }
    return popped;                                          //return data popped off dataStack
}

int getMinPeek(struct getMinStack* top)
{
    return peek((*top).dataStack);
}

int getMinIsEmpty(struct getMinStack* top)
{
    return isEmpty((*top).dataStack);
}

void getMinPrintStack(struct getMinStack* top)
{
    printStack((*top).dataStack);
}

int getMin(struct getMinStack* top)
{
    return peek((*top).minStack);
}
