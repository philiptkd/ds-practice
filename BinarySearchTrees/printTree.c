//this file contains three different ways to traverse and print a binary tree
//all take O(n) time, as they visit each node once
//most are depth first traversals, which take O(h) extra space on the call stack, where h is the maximum height of the tree
//the breadth first traversal takes O(w) extra space on the heap, where w is the maximum width of the tree

#include "main.h"
#include <stdio.h>

//in binary search trees, inorder traversal gives nondecreasing order
void printTreeInOrder(struct treeNode* root)
{
    if(!root)       //an empty tree doesn't need printing
        return;

    //print left side
    if(root->left)
    {
        printTreeInOrder(root->left);
    }

    //print root
    printf("%d ", root->data);

    //print right side
    if(root->right)
    {
        printTreeInOrder(root->right);
    }
}

//preorder traversal is useful for copying trees
void printTreePreOrder(struct treeNode* root)
{
    if(!root)       //an empty tree doesn't need printing
        return;

    //print root
    printf("%d ", root->data);

    //print left side
    if(root->left)
    {
        printTreePreOrder(root->left);
    }

    //print right side
    if(root->right)
    {
        printTreePreOrder(root->right);
    }
}

//postorder traversal is useful for deleting trees
void printTreePostOrder(struct treeNode* root)
{
    if(!root)       //an empty tree doesn't need printing
        return;

    //print left side
    if(root->left)
    {
        printTreePostOrder(root->left);
    }

    //print right side
    if(root->right)
    {
        printTreePostOrder(root->right);
    }

    //print root
    printf("%d ", root->data);
}

//level order traversal is useful for breadth first searches
//on my 32-bit machine, int's and pointers are the same size
void printTreeLevelOrder(struct treeNode* root)
{
    if(!root)       //an empty tree doesn't need printing
        return;

    struct queueNode* q = 0;    //queue for tree nodes
    enqueue(&q, (int)root);
    printf("%d ", root->data);

    while(!isEmpty(q))
    {
        struct treeNode* node = (struct treeNode*)dequeue(&q);
        if(node->left)
        {
            enqueue(&q, (int)node->left);
            printf("%d ", node->left->data);
        }

        if(node->right)
        {
            enqueue(&q, (int)node->right);
            printf("%d ", node->right->data);
        }
    }
    printf("\n");
}
