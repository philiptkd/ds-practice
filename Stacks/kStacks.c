//this file holds functions implementing up to 10 different stacks using just one array
//I arbitrarily choose an array size of 10, but any amount of memory could be allocated if k were known beforehand
//because I hard code the array size to 10, k <= 10 in this example

//can use peek(), isEmpty(), and printStack() from linkedListStack.c as normal

#include "main.h"
#include <stdlib.h>

struct kStacks* createEmptyKStacks()
{
    struct kStacks* kStack = (struct kStacks*)malloc(sizeof(struct kStacks));   //allocate memory for metadata

    int len = 10;           //set length
    (*kStack).N = len;

    (*kStack).nextEmpty = (struct stackNode*)malloc(len*sizeof(struct stackNode));  //allocate memory for stack data

    struct stackNode* empties = (*kStack).nextEmpty;    //for readability
    int i;
    for(i=0; i<len-1; i++)          //point every stack node structure in the array to the one immediately after it in memory
    {
        (empties + i)->next = (empties + i + 1);
    }
    (empties + i)->next = 0;        //for i = len-1, the last element

    return kStack;
};

struct stackNode* createOneOfKStacks(struct kStacks* kStack, int data)      //creates a stack and pushes first element
{
    struct stackNode* top = (*kStack).nextEmpty;        //allocate memory from array for new stack
    if(top)
    {
        (*kStack).nextEmpty = (kStack->nextEmpty)->next;    //update pointer to next empty element in array
        (*top).next = 0;                //initialize fields for this stack node
        (*top).data = data;
    }
    return top;     //returns 0 if there was no room
};

//assumes *top points to a nonempty stack
int pushOntoKStack(struct kStacks* kStack, struct stackNode** top, int data)
{
    struct stackNode* newTop = (*kStack).nextEmpty;        //allocate memory from array for new stack
    if(newTop)          //if there was room
    {
        (*kStack).nextEmpty = (kStack->nextEmpty)->next;    //update pointer to next empty element in array
        (*newTop).next = *top;          //set pointer
        (*newTop).data = data;          //set data
        *top = newTop;                  //rename top
        return 1;
    }
    return 0;       //if there was not room
}

//assumes *top points to a nonempty stack
int popOffOfKStack(struct kStacks* kStack, struct stackNode** top)
{
    int ret = (**top).data;     //to return

    struct stackNode* newTop = (**top).next;        //the next node on the stack, if there is one

    (**top).next = (*kStack).nextEmpty;             //the old top is now free to be a part of the list of empty structs
    (*kStack).nextEmpty = *top;             //old top is now at the top of the empties stack

    *top = newTop;      //if *top is now 0, the last element on the stack was popped off
    return ret;
}
