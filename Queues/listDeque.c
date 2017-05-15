//this file contains an implementation of a deque (double ended queue) using a circular doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include "main.h"


//exactly the same as insertBack() or enqueue(), except "back" is not renamed.
void insertFront(struct queueNode** back, int data)
{
    struct queueNode* newFront = (struct queueNode*)malloc(sizeof(struct queueNode));   //allocate memory for new node
    (*newFront).data = data;

    if(*back)    //if the queue was not empty
    {
        struct queueNode* front = (**back).prev;     //the front is the last node of the list

        (*newFront).prev = front;        //set new node's pointers
        (*newFront).next = *back;
        (*front).next = newFront;        //reset old nodes' pointers
        (**back).prev = newFront;
    }

    else    //if the queue was empty
    {
        (*newFront).prev = newFront;
        (*newFront).next = newFront;
        *back = newFront;
    }
}

void insertBack(struct queueNode** back, int data)
{
    enqueue(back, data);
}

void deleteFront(struct queueNode** back)
{
    if(isEmptyDeque(*back))     //if the deque is empty, do nothing
        return;

    struct queueNode* front = (**back).prev;        //old front of queue

    if(front == *back)      //if there is only one node in the queue
    {
        free(front);        //free memory
        *back = 0;          //rename back to indicate the queue is empty
    }
    else
    {
        struct queueNode* newFront = (*front).prev;     //new front of queue
        (*newFront).next = *back;                   //update pointers
        (**back).prev = newFront;
        free(front);        //free memory allocated for node
    }
}

void deleteBack(struct queueNode** back)
{
    if(isEmptyDeque(*back))     //if the deque is empty, do nothing
        return;

    struct queueNode* front = (**back).prev;    //front of the queue

    if(front == *back)      //if there was only one node in the queue
    {
        free(*back);        //free memory
        *back = 0;          //rename back to indicate queue is empty
    }
    else
    {
        struct queueNode* newBack = (**back).next;      //new back of queue

        (*front).next = newBack;        //update pointers
        (*newBack).prev = front;
        free(*back);                //free memory
        *back = newBack;            //rename back
    }

}

int getFront(struct queueNode* back)
{
    return frontVal(back);
}

int getBack(struct queueNode* back)
{
    return backVal(back);
}

int isEmptyDeque(struct queueNode* back)
{
    return isEmpty(back);
}

void printDeque(struct queueNode* back)
{
    printQueue(back);
}
