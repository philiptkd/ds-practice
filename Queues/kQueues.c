//this file contains the functions necessary to implement up to k queues within one array
//once user has pointer to queue of interest, can use frontVal(), backVal(), isEmpty(), and printQueue() as normal

#include "main.h"
#include <stdlib.h>

//allocates memory for and initializes the array to hold up to k queues
//assumes k>=2
struct kQueue* createKQ(int k)
{
    struct kQueue* kQ = (struct kQueue*)malloc(sizeof(struct kQueue));      //allocate memory for metadata
    kQ->k = k;
    struct queueNode* empties = (struct queueNode*)malloc(k*sizeof(struct queueNode));       //allocate memory for data
    kQ->empties = empties;

    //initialize endpoint nodes
    (empties + 0)->data = 0;
    (empties + 0)->prev = 0;
    (empties + 0)->next = (empties + 0 + 1);
    (empties + k-1)->data = 0;
    (empties + k-1)->prev = (empties + k-1 - 1);
    (empties + k-1)->next = 0;

    //initialize rest of nodes
    int i;
    for(i=1; i<k-1; i++)
    {
        (empties + i)->data = 0;
        (empties + i)->prev = (empties + i - 1);
        (empties + i)->next = (empties + i + 1);
    }

    return kQ;
}

//adds a queue to the kQueue array and enqueues the first value
struct queueNode* addQueue(struct kQueue* kQ, int data)
{
    struct queueNode* newQueue = kQ->empties;      //get first node of new queue from empties memory

    if(newQueue)            //if there was room
    {
        kQ->empties = (kQ->empties)->next;          //point empties to next empty node
        if(kQ->empties)
            { (kQ->empties)->prev = 0; }

        newQueue->data = data;                      //initialize values for node
        newQueue->prev = newQueue;
        newQueue->next = newQueue;
    }

    return newQueue;
}

//assumes queue is not empty
void enKQueue(struct kQueue* kQ, struct queueNode** back, int data)
{
    struct queueNode* newBack = kQ->empties;

    if(newBack)     //if there was room
    {
        kQ->empties = (kQ->empties)->next;          //rename empties
        if(kQ->empties)
            { (kQ->empties)->prev = 0; }                   //first node in empty array shouldn't point to a full node

        struct queueNode* front = (*back)->prev;       //get pointer to front of the queue

        newBack->data = data;                       //set data and pointers for new node
        newBack->prev = front;
        newBack->next = *back;

        front->next = newBack;                      //set pointers of surrounding nodes
        (*back)->prev = newBack;

        *back = newBack;                            //rename back
    }
}

//assumes queue is not empty
int deKQueue(struct kQueue* kQ, struct queueNode** back)
{
    struct queueNode* front = (*back)->prev;        //node to be dequeued
    int ret = front->data;

    //make changes to queue
    if(front == *back)      //if there was only one node in queue
    {
        *back = 0;          //rename back to show it is empty
    }
    else
    {
        struct queueNode* newFront = front->prev;       //the new front of the queue
        newFront->next = *back;                         //set pointers
        (*back)->prev = newFront;
    }

    //add the front node back to the empties list
    if(kQ->empties)
        { (kQ->empties)->prev = front; }
    struct queueNode* tmp = kQ->empties;
    kQ->empties = front;
    (kQ->empties)->next = tmp;
    (kQ->empties)->prev = 0;

    free(front);
    return ret;
}
