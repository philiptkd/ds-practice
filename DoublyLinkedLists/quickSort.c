#include "main.h"

void swap(struct doubleNode* n, struct doubleNode* m);
void printConnections(struct doubleNode* head);

//implements quick sort for a doubly linked list
void quickSort(struct doubleNode** head, struct doubleNode* origLeft, struct doubleNode* origRight)
{
    struct doubleNode* left = origLeft;
    struct doubleNode* right = origRight;
    struct doubleNode* pivot = (*right).next;       //get index of node to the right of "right"

    while(right && left && left != (*right).next)
    {
        //if neither are on the right side, swap them
        if(!((*left).val < (*pivot).val) && !((*right).val > (*pivot).val))
        {
            swap(left, right);
            if(left == origLeft)
            {
                origLeft = right;
            }
            if(right == origRight)
            {
                origRight = left;
            }

            struct doubleNode* tmp = left;
            left = (*right).next;   //it would be left = (*left).next, but we swapped the pointers
            right = (*tmp).prev;   //it would be right = (*right).prev, but we swapped the pointers
        }
        else
        {
            if((*left).val < (*pivot).val)
            {
                left = (*left).next;
            }
            if((*right).val > (*pivot).val)
            {
                right = (*right).prev;
            }
        }
    }

    //here left = (*right).next or right = 0, so (*left).val > (*pivot).val
    //swap items at left and pivot
    swap(left, pivot);
    if(left == origLeft)
    {
        origLeft = pivot;
    }

    int count = 0;
    left = origLeft;
    right = (*origRight).next;
    while(left != pivot)
    {
        count++;
        left = (*left).next;
    }

    //sort left half
    if(count > 1)        //if there is more than one element to the left of the pivot
    {
        quickSort(head, origLeft, (*(*pivot).prev).prev);
    }

    count = 0;
    while(right != pivot)
    {
        count++;
        right = (*right).prev;
    }

    //sort right half
    if(count > 1)     //if there is more than one element to the right of the pivot
    {
        quickSort(head, (*pivot).next, origRight);
    }

    *head = origLeft;       //set head to be the new leftmost node
}
