#include "main.h"

struct doubleNode* append(struct doubleNode* leftHead, struct doubleNode* rightHead);

//converts a binary tree to a circular doubly linked list
struct doubleNode* tree2List(struct leaf* top)
{
    //get list for left half
    struct doubleNode* leftHead = 0;
    if((*top).left)
    {
        leftHead = tree2List((*top).left);
    }

    //get list for right half
    struct doubleNode* rightHead = 0;
    if((*top).right)
    {
        rightHead = tree2List((*top).right);
    }

    //combine in the order left->top->right
    (*top).left = top;   //prep for append()
    (*top).right = top;

    struct doubleNode* bigList = (struct doubleNode*)top;
    if(leftHead)
    {
        bigList = append(leftHead, bigList);
    }
    if(rightHead)
    {
        bigList = append(bigList, rightHead);
    }

    return bigList;
}
