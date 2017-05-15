#include "main.h"
#include <stdlib.h>

//merge sorts a doubly linked list
//returns leftHead
struct doubleNode* mergeSort(struct doubleNode* leftHead, struct doubleNode* rightTail, int len, struct doubleNode* leftHeadPrev, struct doubleNode* rightTailNext)
{
    //a single node is already sorted
    if(leftHead == rightTail)
    {
        return leftHead;
    }

    //find start of right half
    struct doubleNode* rightHead = leftHead;
    int i;
    for(i=0; i<len/2; i++)
    {
        rightHead = (*rightHead).next;
    }

    //find end of left half
    struct doubleNode* leftTail = (*rightHead).prev;

    //sort left half
    leftHead = mergeSort(leftHead, leftTail, len/2, (*leftHead).prev, (*leftTail).next);

    //sort right half
    rightHead = mergeSort(rightHead, rightTail, len - len/2, (*rightHead).prev, (*rightTail).next);

    //merge halves
    struct doubleNode* prev = leftHeadPrev;
    int leftCount = len/2;
    int rightCount = len - len/2;

    struct doubleNode* origLeftHead = leftHead;
    for(i=0; i<len; i++)
    {
        if(leftCount == 0)                      //if there are no more nodes from the left side, take from right side
        {
            (*rightHead).prev = prev;               //set r's prev pointer to the last node sorted
            if(prev)
                { (*prev).next = rightHead; }       //set the next pointer of the last node sorted
            prev = rightHead;                       //r is now the last node sorted
            rightHead = (*rightHead).next;          //let the next node in the right side be r
            rightCount--;                       //there is one less node to take from the right side
        }
        else if(rightCount == 0)                //if there are no more nodes from the right side, take from left side
        {
            (*leftHead).prev = prev;
            if(prev)
                { (*prev).next = leftHead; }
            prev = leftHead;
            leftHead = (*leftHead).next;
            leftCount--;
        }
        else if((*leftHead).val < (*rightHead).val)     //if the first node on the left's value is less than that of the node on the right
        {                                                   //take from the left
            (*leftHead).prev = prev;
            if(prev)
                { (*prev).next = leftHead; }
            prev = leftHead;
            leftHead = (*leftHead).next;
            leftCount--;
        }
        else    //if (*r).val <= (*l).val        //if the first node on the right's value is less than that of the node on the left
        {                                                               //take from the right
            if(i == 0)
                { origLeftHead = rightHead; }

            (*rightHead).prev = prev;
            if(prev)
                { (*prev).next = rightHead; }
            prev = rightHead;
            rightHead = (*rightHead).next;
            rightCount--;
        }
    }

    (*prev).next = rightTailNext;               //let the last node sorted point to the next node on the list that wasn't sorted
    if(rightTailNext)
        { (*rightTailNext).prev = prev; }       //let that next node, if it exists, point back to the last node sorted

    return origLeftHead;
}
