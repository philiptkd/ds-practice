#include "main.h"
#include <stdlib.h>

struct listNode* newListNode(int data)
{
    struct listNode* ret = (struct listNode*)malloc(sizeof(struct listNode));
    ret->data = data;
    ret->next = 0;
    ret->prev = 0;

    return ret;
}

void append2List(struct listNode** circList, int data)
{
    struct listNode* node = newListNode(data);

    if(*circList == 0)
    {
        node->next = node;
        node->prev = node;

        *circList = node;
    }
    else
    {
        struct listNode* lastNode = (*circList)->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = *circList;
        (*circList)->prev = node;
    }
}
