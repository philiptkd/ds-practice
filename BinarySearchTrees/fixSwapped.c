#include "main.h"
#include <stdio.h>

//takes a BST where exactly two of the nodes have been swapped
//fixes it
//completes in O(n) time and O(h) extra space
void fixSwapped(struct treeNode* root)
{
    struct stackNode* treeStack = 0;
    struct treeNode* alreadyVisited = (struct treeNode*)(-1);
    struct treeNode* latestInOrder = 0;
    struct treeNode* tooBig = 0;
    struct treeNode* afterTooBig = 0;

    while(root)
    {
        if(root->right == alreadyVisited)                   //if we have just visit the right subtree
        {
            alreadyVisited = root;
            if(treeStack)
                root = (struct treeNode*)pop(&treeStack);         //go up the tree if we can
            else
                root = 0;
        }
        else if(root->left && root->left != alreadyVisited) //if we haven't yet visited the left subtree
        {
            push(&treeStack, (int)root);                        //go there first
            root = root->left;
        }
        else                                    //there isn't a left subtree we haven't visited already
        {                                           //and we haven't visited this node already, either
            if(tooBig && root->data < latestInOrder->data)    //if it's the second one out of order
            {
                //swap them
                int tmp = tooBig->data;
                tooBig->data = root->data;
                root->data = tmp;
                return;
            }
            else if(latestInOrder && root->data < latestInOrder->data)     //else if it's the first one out of order
            {
                tooBig = latestInOrder;     //store this pointer
                afterTooBig = root;
            }

            latestInOrder = root;
            alreadyVisited = root;

            if(root->right)                     //if there is a right subtree
            {
                push(&treeStack, (int)root);        //go there next
                root = root->right;
            }
            else
            {
                if(treeStack)
                    root = (struct treeNode*)pop(&treeStack);   //if there's not, go back up the tree
                else
                    root = 0;
            }
        }
    }

    //if we reached here, the two elements swapped must have been adjacent
    if(tooBig)
    {
        int tmp = tooBig->data;
        tooBig->data = afterTooBig->data;
        afterTooBig->data = tmp;
    }
}
