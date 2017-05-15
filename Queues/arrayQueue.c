//I'm corrupting my call stack somehow
//and it might have something to do with printf
//try saving indexes instead of pointers for front and back
//and use (q->arr)[index] = x or something like that

//UPDATE: that worked. not sure where my mistake was,
    //but I'll use indexes rather than pointers when I can from now on to avoid corrupting something by accident

//this file contains an implementation of a queue using an array

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

struct arrQ* createArrQ(int N)
{
    struct arrQ* q = (struct arrQ*)malloc(sizeof(struct arrQ));     //allocate memory for metadata
    (*q).N = N;
    (*q).arr = (int*)malloc(N*sizeof(int));                         //allocate memory for data
    (*q).iFront = N-1;                      //set front and back to be at the end of the array
    (*q).iBack = N-1;
    (*q).isEmpty = 1;                                               //initialize to empty

    return q;
}

int isFull(struct arrQ* q)
{
    int N = (*q).N;
    if((*q).iBack == (*q).iFront + 1)           //if the back of the queue wrapped around to be one to the right of the front
        return 1;
    if((*q).iFront - (*q).iBack == N-1)    //or if the back is the first element and the front is the last
        return 1;

    return 0;
}

int arrEnqueue(struct arrQ* q, int data)
{
    if(isFull(q))
        return -1;          //indicates overflow

    if((*q).isEmpty)
    {
        (q->arr)[q->iBack] = data;               //here back = front, and we don't want to change that
        (*q).isEmpty = 0;                   //the queue is now not empty
    }
    else
    {
        moveBack(q);                    //move the pointer to the new back of the line
        (q->arr)[q->iBack] = data;                   //set the value at the new back
    }
    return 1;
}

int arrDequeue(struct arrQ* q)
{
    if(q->isEmpty)
        return -1;

    int ret = (q->arr)[q->iFront];
    if(q->iFront == q->iBack)
    {
        q->isEmpty = 1;
    }
    else
    {
        moveFront(q);
    }

    return ret;
}

int arrQFront(struct arrQ* q)
{
    if(q->isEmpty)
        return -1;

    return (q->arr)[q->iFront];
}

int arrQBack(struct arrQ* q)
{
    if(q->isEmpty)
        return -1;

    return (q->arr)[q->iBack];
}

//assumes there is room to move back without encroaching on front
void moveBack(struct arrQ* q)
{
    int N = (*q).N;
    if(q->iBack == 0)           //if the back of the line is at the first element of the array
    {
        q->iBack = N-1;      //wrap around to the last element of the array
    }
    else
    {
        q->iBack = (q->iBack) - 1;    //otherwise, just move back by one
    }
}

void moveFront(struct arrQ* q)
{
    int N = (*q).N;
    if(q->iFront == 0)           //if the front of the line is at the first element of the array
    {
        q->iFront = N-1;      //wrap around to the last element of the array
    }
    else
    {
        q->iFront = (q->iFront) - 1;    //otherwise, just move front by one
    }
}

void printArrQ(struct arrQ* q)
{
    if(q->isEmpty)          //do nothing if the queue is empty
        return;

    int i = q->iBack;
    int N = (*q).N;
    printf("%d ", (q->arr)[i]);       //print the first one

    while(i != q->iFront)     //print the rest
    {
        if(i == N-1)         //if i points to the last element of the array
        {
            i = 0;    //point it to the first
        }
        else
        {
            i++;        //otherwise, move it to the left by one
        }

        printf("%d ", (q->arr)[i]);
    }
}

void destroyArrQ(struct arrQ* q)
{
    free(q->arr);
    free(q);
}
