#include <stdlib.h>
#include <stdio.h>
#include "main.h"

//this file contains the essential functions for implementing a stack with a singly linked list

int stackIsEmpty(struct stackNode* top)
{
    if(top)
    {
        return 0;
    }
    return 1;
}

//because we also have isEmpty(), this function assumes that the stack is not empty
int peek(struct stackNode* top)
{
    return (*top).data;
}

int pop(struct stackNode** oldTop)
{
    int ret = (**oldTop).data;
    struct stackNode* newTop = (**oldTop).next;
    free(*oldTop);
    *oldTop = newTop;

    return ret;
}

//prints a stack implemented with a singly linked list
void printStack(struct stackNode* top)
{
    while(top)
    {
        printf("%d ", (*top).data);
        top = (*top).next;
    }
    //printf("\n");
}

//pushes a new element onto the top of the (singly linked list) stack
void push(struct stackNode** oldTop, int data)
{
    struct stackNode* newTop = (struct stackNode*)malloc(sizeof(struct stackNode));
    (*newTop).data = data;
    (*newTop).next = *oldTop;
    *oldTop = newTop;
}

