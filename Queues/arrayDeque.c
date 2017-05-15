#include "main.h"

//implements a deque using a fixed amount of memory in an array

struct arrQ* createArrDeque(int N)
{
    return createArrQ(N);
}

void insertFrontArr(struct arrQ* q, int data)
{
    if(isFull(q))
        return;          //if overflow, do nothing

    if((*q).isEmpty)
    {
        (q->arr)[q->iFront] = data;               //here back = front, and we don't want to change that
        (*q).isEmpty = 0;                   //the queue is now not empty
    }
    else
    {
        moveFrontFwd(q);                    //move the pointer to the new front of the line
        (q->arr)[q->iFront] = data;                   //set the value at the new front
    }
}

void insertBackArr(struct arrQ* q, int data)
{
    arrEnqueue(q, data);
}

void deleteFrontArr(struct arrQ* q)
{
    if((*q).isEmpty)
        return;

    if(q->iFront == q->iBack)
    {
        q->isEmpty = 1;                     //if there was only one element, indicate queue is now empty
    }
    else
    {
        moveFront(q);           //decrements the index of the front of the array
    }
}

void deleteBackArr(struct arrQ* q)
{
    if((*q).isEmpty)
        return;

    if(q->iFront == q->iBack)
    {
        q->isEmpty = 1;                     //if there was only one element, indicate queue is now empty
    }
    else
    {
        moveBackFwd(q);           //increments the index of the back of the array
    }
}

int getFrontArr(struct arrQ* q)
{
    return arrQFront(q);
}

int getBackArr(struct arrQ* q)
{
    return arrQBack(q);
}

//assumes not empty
void moveBackFwd(struct arrQ* q)
{
    int N = (*q).N;
    if(q->iBack == N-1)
    {
        q->iBack = 0;
    }
    else
    {
        q->iBack = q->iBack + 1;
    }
}

//assumes not full
void moveFrontFwd(struct arrQ* q)
{
    int N = (*q).N;
    if(q->iFront == N-1)
    {
        q->iFront = 0;
    }
    else
    {
        q->iFront = q->iFront + 1;
    }
}

void printArrDeque(struct arrQ* q)
{
    printArrQ(q);
}

void destroyArrDeque(struct arrQ* q)
{
    destroyArrQ(q);
}
