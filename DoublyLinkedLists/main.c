#include "main.h"
#include <stdio.h>

struct doubleNode* createList();
void printList(struct doubleNode* head);
void quickSort(struct doubleNode** head, struct doubleNode* origLeft, struct doubleNode* origRight);
void swapKths(struct doubleNode** head, int K);
struct doubleNode* mergeSort(struct doubleNode* leftHead, struct doubleNode* rightTail, int len, struct doubleNode* leftHeadPrev, struct doubleNode* rightTailNext);

int main()
{
    struct doubleNode* head = createList();
    printList(head);

    //find tail
    struct doubleNode* tail = head;
    int len = 1;
    while((*tail).next)
    {
        tail = (*tail).next;
        len++;
    }

    head = mergeSort(head, tail, len, 0, 0);

    printList(head);
    return 0;
}
