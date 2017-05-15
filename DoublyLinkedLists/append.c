#include "main.h"

//appends one circular doubly linked list to another
//leftHead...leftTail<->rightHead...rightTail<->leftHead
struct doubleNode* append(struct doubleNode* leftHead, struct doubleNode* rightHead)
{
    struct doubleNode* leftTail = (*leftHead).prev;
    struct doubleNode* rightTail = (*rightHead).prev;

    (*leftTail).next = rightHead;   //leftTail->rightHead
    (*rightHead).prev = leftTail;   //leftTail<-rightHead
    (*rightTail).next = leftHead;   //rightTail->leftHead
    (*leftHead).prev = rightTail;   //rightTail<-leftHead

    return leftHead;
}
