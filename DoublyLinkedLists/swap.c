#include "main.h"

//swaps two nodes in a doubly linked list by altering pointers
void swap(struct doubleNode* n, struct doubleNode* m)
{
    struct doubleNode* tmp;

    if((*n).prev && (*n).prev != m)
        (*(*n).prev).next = m;

    if((*n).next && (*n).next != m)
        (*(*n).next).prev = m;

    if((*m).prev && (*m).prev != n)
        (*(*m).prev).next = n;

    if((*m).next && (*m).next != n)
        (*(*m).next).prev = n;

    if(n == (*m).prev)
    {
        (*m).prev = (*n).prev;
        (*n).prev = m;

        (*n).next = (*m).next;
        (*m).next = n;
    }
    else if(m == (*n).prev)
    {
        (*n).prev = (*m).prev;
        (*m).prev = n;

        (*m).next = (*n).next;
        (*n).next = m;
    }
    else
    {
        tmp = (*n).prev;
        (*n).prev = (*m).prev;
        (*m).prev = tmp;

        tmp = (*n).next;
        (*n).next = (*m).next;
        (*m).next = tmp;
    }
}
