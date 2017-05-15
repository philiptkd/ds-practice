#include "main.h"

//returns the value at the Nth node from the end of the list
int nthFromEnd(struct node* head, int N)
{
    struct node* leader = head;         //the pointer to traverse the list first
    struct node* follower = head;       //the pointer to follow leader N steps behind
    int gap = 0;                        //the distance between leader and follower in nodes

    while((*leader).next)               //while there is a next node
    {
        leader = (*leader).next;        //go to it
        if(gap == N)
        {
            follower = (*follower).next;
        }
        else
        {
            gap++;
        }
    }

    if(gap < N)             //if the list was not of greater length than N
        return -1;

    return (*follower).val;
}
