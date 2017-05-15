#include <stdlib.h>
#include <stdio.h>
#include "main.h"

//this file contains the essential functions for implementing a stack with a singly linked list

//creates a stack using a singly linked list
struct stackNode* createStack(int N)
{
    struct stackNode* addr[N];
    addr[0] = (struct stackNode*)malloc(sizeof(struct stackNode));
    (*addr[0]).data = 1;
    (*addr[0]).next = 0;

    int i;
    for(i=1; i<N; i++)
    {
        addr[i] = (struct stackNode*)malloc(sizeof(struct stackNode));
        (*addr[i-1]).next = addr[i];
        (*addr[i]).data = i+1;
        (*addr[i]).next = 0;
    }

    return addr[0];
}

int isEmpty(struct stackNode* top)
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
    printf("\n");
}

//pushes a new element onto the top of the (singly linked list) stack
void push(struct stackNode** oldTop, int data)
{
    struct stackNode* newTop = (struct stackNode*)malloc(sizeof(struct stackNode));
    (*newTop).data = data;
    (*newTop).next = *oldTop;
    *oldTop = newTop;
}

