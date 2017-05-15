#include "main.h"

int isTreeBST(struct treeNode* root, int upperBound, int lowerBound, int upperBoundActive, int lowerBoundActive);

//takes a tree and returns 1 if it is a Binary Search Tree
//is wrapper for recursive function with more parameters
int isBST(struct treeNode* root)
{
    return isTreeBST(root, 0, 0, 0, 0);
}

int isTreeBST(struct treeNode* root, int upperBound, int lowerBound, int upperBoundActive, int lowerBoundActive)
{
    if(root == 0)       //we define an empty tree as a valid BST
        return 1;

    if(root->left == 0 && root->right == 0)     //we define a single node as a valid BST
        return 1;

    int leftIsBST = 1;      //initialize to 1 so nodes with only one child can pass the final if statement
    int rightIsBST = 1;

    if(root->left)      //if there is a left child
    {
        if(lowerBoundActive)        //if the path there from the root ever makes a right turn
        {
            if(root->left->data <= lowerBound)      //if it makes some subtree an invalid BST
                return 0;
        }

        if(root->left->data >= root->data)      //if left is not less
            return 0;

        leftIsBST = isTreeBST(root->left, root->data, lowerBound, 1, lowerBoundActive);     //this node is left child's upper bound
    }

    if(root->right)     //if there is a right child
    {
        if(upperBoundActive)    //if the path there from the root ever makes a left turn
        {
            if(root->right->data >= upperBound)     //if it makes some subtree an invalid BST
                return 0;
        }

        if(root->right->data <= root->data)     //if right is not greater
            return 0;

        rightIsBST = isTreeBST(root->right, upperBound, root->data, upperBoundActive, 1);   //this node is right child's lower bound
    }

    if(leftIsBST && rightIsBST)
        return 1;
    else
        return 0;
}
