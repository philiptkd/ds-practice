#include "main.h"
#include <stdio.h>

//takes a BST where two of the nodes have been swapped
//fixes it
//completes in O(n) time
void printInOrderWStack(struct treeNode* root)
{
    struct stackNode* treeStack = 0;
    struct treeNode* alreadyPrinted = (struct treeNode*)(-1);

    while(root)
    {
        if(root->right == alreadyPrinted)                   //if we have just printed the right subtree
        {
            alreadyPrinted = root;
            if(treeStack)
                root = (struct treeNode*)pop(&treeStack);         //go up the tree if we can
            else
                root = 0;
        }
        else if(root->left && root->left != alreadyPrinted) //if we haven't yet printed the left subtree
        {
            push(&treeStack, (int)root);                        //go there first
            root = root->left;
        }
        else                                    //there isn't a left subtree we haven't printed already
        {                                           //and we haven't printed this node already, either
            printf("%d ", root->data);                  //so print it
            alreadyPrinted = root;

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
}
