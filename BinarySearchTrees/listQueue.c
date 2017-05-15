//this file contains an implementation of a queue using a circular doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void enqueue(struct queueNode** back, int data)        //to enqueue is to add to the back of the line (first node of the list)
{
    struct queueNode* newBack = (struct queueNode*)malloc(sizeof(struct queueNode));   //allocate memory for new node
    (*newBack).data = data;

    if(*back)    //if the queue was not empty
    {
        struct queueNode* front = (**back).prev;     //the front is the last node of the list

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

//because we have isEmpty(), assumes not empty
int dequeue(struct queueNode** back)
{
    struct queueNode* front = (**back).prev;        //the front is the last node of the list
    int ret = (*front).data;                        //the value to be returned

    if(front == *back)        //if the queue had only one node
    {
        *back = 0;
    }
    else
    {
        struct queueNode* newFront = (*front).prev;     //the new front node after this one is dequeued
        (*newFront).next = *back;                       //reset pointers
        (**back).prev = newFront;
    }

    free(front);                                    //free memory for front node
    return ret;
}

int frontVal(struct queueNode* back)
{
    return (*(*back).prev).data;
}

int backVal(struct queueNode* back)
{
    return (*back).data;
}

int isEmpty(struct queueNode* back)
{
    if(back)
        return 0;       //queue is not empty if the back element has an address
    else
        return 1;
}

void printQueue(struct queueNode* back)
{
    if(!back)                   //stop if the queue is empty
        return;

    printf("%d ", (*back).data);        //print the first value

    struct queueNode* qn = back;
    while((*qn).next && (*qn).next != back)
    {
        qn = (*qn).next;
        printf("%d ", (*qn).data);
    }
    printf("\n");
}
