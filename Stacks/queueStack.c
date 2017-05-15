//this file contains an implementation of a stack using only queues
//the idea is to have two queues
//one queue is to only hold the most recently pushed value
//the other is to hold the rest
//pop takes O(n) time when done more than once in a row without pushing
//must initialize pointers to the two queues to 0 before pushing to them

#include "main.h"
#include <stdio.h>

void queueStackPush(struct queueStack* qStack, int data)
{
    if(!queueIsEmpty((*qStack).popQueue))       //if the queue holding the most recently pushed item is full
    {
        int toMove = dequeue(&((*qStack).popQueue));        //transfer it to the main queue that holds the rest of the values
        enqueue(&((*qStack).mainQueue), toMove);
    }

    enqueue(&((*qStack).popQueue), data);          //put the new data into popQueue
}

int queueStackPop(struct queueStack* qStack)
{
    if(queueIsEmpty((*qStack).popQueue))       //if the queue for just one item is empty
    {
        if(queueIsEmpty((*qStack).mainQueue))   //stop if everything is empty
            { return -1; }

        struct queueNode* qn = (*qStack).mainQueue;
        while((*qn).next != qn)                       //transfer all but one item to the other queue
        {
            int toMove = dequeue(&qn);
            enqueue(&((*qStack).popQueue), toMove);
        }

        struct queueNode* tmp = (*qStack).mainQueue;    //switch names so we don't have to put them all back
        (*qStack).mainQueue = (*qStack).popQueue;
        (*qStack).popQueue = tmp;
    }

    return dequeue(&((*qStack).popQueue));
}

int qStackIsEmpty(struct queueStack* qStack)
{
    if(queueIsEmpty((*qStack).popQueue) && queueIsEmpty((*qStack).mainQueue))
        return 1;
    else
        return 0;
}

//because we have isEmpty(), assumes not empty
int qStackPeek(struct queueStack* qStack)
{
    if(!queueIsEmpty((*qStack).popQueue))
    {
        return front((*qStack).popQueue);
    }
    else
    {
        return back((*qStack).mainQueue);
    }
}

void printQStack(struct queueStack* qStack)     //prints stack from bottom to top
{
    printQueue((*qStack).popQueue);
    printQueue((*qStack).mainQueue);
    printf("\n");
}
