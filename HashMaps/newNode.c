#include "main.h"
#include <stdlib.h>

//creates a leaf of a tree
struct treeNode* newNode(int data)
{
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->data = data;
    node->left = 0;
    node->right = 0;
    return node;
}
