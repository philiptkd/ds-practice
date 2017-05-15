#include "main.h"
#include <stdio.h>

//takes a tree and prints it in order using constant extra space, even considering the function call stack
//does it iteratively by first altering some of the tree's NULL pointers and using Morris traversal
void threadTree(struct treeNode* root)
{
    if(root == 0)       //handle empty tree case
        return;


    struct treeNode* current = root;

    //the below condition is sufficient, because...
        //we only traverse the tree blindly in the right direction
        //except for in the rightmost node, any NULL right pointer will be replaced with a successor pointer in traversal
    while(current)        //until we reach the rightmost node of the tree
    {
        if(current->left == 0)      //if this node doesn't have a left subtree, there are no more nodes to be printed before itself
        {
            printf("%d ", current->data);
            current = current->right;

            //here, we are possibly traversing through a successor pointer
            //but if we are, we will discover it during the next loop and repair that part of the tree
        }
        else
        {
            struct treeNode* predecessor = current->left;       //the node to point RIGHT to current

            //find the rightmost node in current node's left subtree
            while(predecessor->right != 0 && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            //if we have looped back around to the current node, it means we have printed the left subtree already
            if(predecessor->right == current)
            {
                predecessor->right = 0;     //restore the pointer we changed
                printf("%d ", current->data);   //print this middle node
                current = current->right;       //and move on to the right subtree
            }

            else        //if predecessor->right == 0
            {
                predecessor->right = current;   //point to its successor
                current = current->left;        //continue down the left subtree
            }
        }
    }
}
