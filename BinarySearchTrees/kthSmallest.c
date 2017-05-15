#include "main.h"
#include <stdlib.h>

void kthSmallestNode(struct treeNode* root, int k, int* count, int** ans);

//finds the kth smallest node in a BST by traversing it inOrder
//is a wrapper for a recursive function with more parameters
//if k > the size of the tree, returns -1
int kthSmallest(struct treeNode* root, int k)
{
    if(root == 0 || k <= 0)
        return -1;

    int* ans = 0;
    int count = 0;

    kthSmallestNode(root, k, &count, &ans);

    if(ans)
        return *ans;
    else
        return -1;
}

void kthSmallestNode(struct treeNode* root, int k, int* count, int** ans)
{
    if(*ans)                         //if we've found the answer already, return up the call stack
        return;

    if(root->left == 0 && *count == 0)      //if we've reached the leftmost node, start counting
    {
        *count = 1;
    }

    if(root->left)                                      //traverse the left subtree
        kthSmallestNode(root->left, k, count, ans);

    if(*ans)                         //if we just found the answer, return up the call stack
        return;

    //deal with this node
    if(*count == k)                 //if we've counted k nodes, this is the node we want
    {
        *ans = (int*)malloc(sizeof(int));
        **ans = root->data;
        return;
    }
    else if(count)             //if we haven't found it yet, but we're proceeding forward and have started counting
    {
        *count = *count + 1;          //keep counting
    }


    if(root->right)                                     //traverse the right subtree
        kthSmallestNode(root->right, k, count, ans);
}
