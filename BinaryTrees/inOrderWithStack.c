//just like printTreeInOrder() but uses a stack other than the function call stack
//using a stack meant to hold int's for pointers. it works on my 32bit machine
//could be optimized by not pushing and popping from stack as much, but I'd need a different while condition

#include "main.h"
#include <stdio.h>

void inOrderWithStack(struct treeNode* root)
{
    if(!root)           //nothing to print if there is no tree
        return;

    struct stackNode* treeStack = 0;        //stack to hold tree nodes
    struct treeNode* lastPrinted = (struct treeNode*)(-1);       //to hold the last node printed
    push(&treeStack, (int)root);        //push root onto stack

    while(!stackIsEmpty(treeStack))
    {
        struct treeNode* node = (struct treeNode*)pop(&treeStack);  //pop off the most recent tree node added

        if(lastPrinted == node->right)
        {
            lastPrinted = node;     //reset lastPrinted to keep track of position in tree
                                    //don't print anything, though. this node was already printed
        }
        else if(!node->left || lastPrinted == node->left)             //if there is no left node, or if its already been printed
        {
            printf("%d ", node->data);       //the "root" can be printed
            lastPrinted = node;
            if(node->right)
                { push(&treeStack, (int)node->right); }    //and the right node can now be traversed
        }
        else    //it has a left node
        {
            push(&treeStack, (int)node);        //push this node
            push(&treeStack, (int)node->left);      //push the left node, to be popped and printed first
        }
    }
}
