#include "main.h"
#include <stdlib.h>

struct treeNode* newNode(int data)
{
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->data = data;
    node->left = 0;
    node->right = 0;

    return node;
}

struct listNode* newListNode(int data)
{
    struct listNode* node = (struct listNode*)malloc(sizeof(struct listNode));
    node->data = data;
    node->prev = 0;
    node->next = 0;

    return node;
}
