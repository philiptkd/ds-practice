#include <stdlib.h>
#include <stdio.h>
#include "main.h"

//this file contains the essential functions for implementing two stacks in one array
//memory is dynamically allocated in the constructor, but then the stacks work with a fixed amount of memory

//N : number of data elements to hold
DblStack* arrayDoubleStack(int N)
{
    DblStack* stack = (DblStack*)malloc(sizeof(DblStack));      //allocates memory for the stack metadata
    (*stack).lastLeftIndex = -1;                                   //-1, an impossible index, indicates that the left stack is empty
    (*stack).lastRightIndex = N;                                   //N, an impossible index, indicates that the right stack is empty
    (*stack).lenDataSection = N;                                   //the length of the data section
    (*stack).stackArray = (int*)malloc(N*sizeof(int));             //allocates memory for the actual stack data
    return stack;
}

int isLeftEmpty(DblStack* stack)
{
    if((*stack).lastLeftIndex == -1)
    {
        return 1;
    }
    return 0;
}

int isRightEmpty(DblStack* stack)
{
    int N = (*stack).lenDataSection;
    if((*stack).lastRightIndex == N)
    {
        return 1;
    }
    return 0;
}

int leftPush(DblStack* stack, int data)
{
    int N = (*stack).lenDataSection;                            //get the length of the array
    int nextIndex = (*stack).lastLeftIndex + 1;                 //get the proposed index to push to
    if(nextIndex < N && nextIndex < (*stack).lastRightIndex)    //if there is room
    {
        *((*stack).stackArray + nextIndex) = data;              //add the data to the array
        (*stack).lastLeftIndex = nextIndex;                     //update the index of the last value added to the left stack
        return 1;
    }
    else
    {
        return -1;                                               //indicates overflow
    }
}

int rightPush(DblStack* stack, int data)
{
    int nextIndex = (*stack).lastRightIndex - 1;                 //get the proposed index to push to
    if(nextIndex >= 0 && nextIndex > (*stack).lastLeftIndex)    //if there is room
    {
        *((*stack).stackArray + nextIndex) = data;              //add the data to the array
        (*stack).lastRightIndex = nextIndex;                     //update the index of the last value added to the right stack
        return 1;
    }
    else
    {
        return -1;                                               //indicates overflow
    }
}

//because we also have the isEmpty()'s, this function assumes the stack is not empty
int leftPop(DblStack* stack)
{
    int lastIndex = (*stack).lastLeftIndex;             //get index of last value added to left stack
    int ret = *((*stack).stackArray + lastIndex);       //get the value
    (*stack).lastLeftIndex = lastIndex - 1;             //update the index
    return ret;
}

//because we also have the isEmpty()'s, this function assumes the stack is not empty
int rightPop(DblStack* stack)
{
    int lastIndex = (*stack).lastRightIndex;             //get index of last value added to right stack
    int ret = *((*stack).stackArray + lastIndex);       //get the value
    (*stack).lastRightIndex = lastIndex + 1;             //update the index
    return ret;
}

//because we also have the isEmpty()'s, this function assumes the stack is not empty
int leftPeek(DblStack* stack)
{
    int lastIndex = (*stack).lastLeftIndex;             //get index of last value added to left stack
    return *((*stack).stackArray + lastIndex);       //return the value
}

//because we also have the isEmpty()'s, this function assumes the stack is not empty
int rightPeek(DblStack* stack)
{
    int lastIndex = (*stack).lastRightIndex;             //get index of last value added to right stack
    return *((*stack).stackArray + lastIndex);       //return the value
}

void printLeftStack(DblStack* stack)
{
    int i;
    for(i=(*stack).lastLeftIndex; i>=0; i--)
    {
        printf("%d ", *((*stack).stackArray + i));
    }
    printf("\n");
}

void printRightStack(DblStack* stack)
{
    int N = (*stack).lenDataSection;
    int i;
    for(i=(*stack).lastRightIndex; i<N; i++)
    {
        printf("%d ", *((*stack).stackArray + i));
    }
    printf("\n");
}

