#include "main.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct StackStructType
{
    struct listNode *top;
    int length;
};

//create empty stack
StackPtr createStack()
{
    StackPtr s = (StackPtr)malloc(sizeof(struct StackStructType));
    s->top = 0;
    s->length = 0;

    return s;
}

//destroy stack
void destroyStack(StackPtr sPtr)
{
    if(!sPtr)
        return;

    struct listNode *nodePtr = sPtr->top;
    while(nodePtr)
    {
        struct listNode *nextPtr = nodePtr->next;
        free(nodePtr);
        nodePtr = nextPtr;
    }

    free(sPtr);
}

//push onto stack
void push(int X, StackPtr sPtr)
{
    struct listNode *newTop = (struct listNode*)malloc(sizeof(struct listNode));
    newTop->key = X;
    newTop->next = sPtr->top;
    sPtr->top = newTop;
    sPtr->length = sPtr->length + 1;
}

//pop off of stack
int pop(StackPtr sPtr)
{
    int ret = sPtr->top->key;
    struct listNode *newTop = sPtr->top->next;
    free(sPtr->top);
    sPtr->top = newTop;
    sPtr->length = sPtr->length - 1;

    return ret;
}

//peek
int peek(StackPtr sPtr)
{
    return sPtr->top->key;
}

//print stack
void printStack(StackPtr sPtr)
{
    struct listNode *nodePtr = sPtr->top;

    while(nodePtr)
    {
        printf("%d ", nodePtr->key);
        nodePtr = nodePtr->next;
    }
    printf("\n");
}
