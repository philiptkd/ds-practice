#include "main.h"

//the diameter of a tree is the length of the longest path between two of its nodes
//the idea behind the solution is that this path either passes through the root, or it does not
//if it does not pass through the root, it is either in the left subtree or the right subtree
//when first called, *height can be anything
//completes in O(n) time with O(1) extra space
int getDiameter(struct treeNode* root, int* height)
{
    if(root==0)     //an empty tree has 0 diameter
    {
        *height = 0;
        return 0;
    }

    if(!root->left && !root->right)     //a single node has a diameter of 1
    {
        *height = 1;
        return 1;
    }

    int leftHeight = 0;
    int leftDiameter = 0;
    int rightHeight = 0;
    int rightDiameter = 0;

    //get diameter and height of left subtree
    if(root->left)
    {
        leftDiameter = getDiameter(root->left, height);
        leftHeight = *height;
    }
    //get diameter and height of right subtree
    if(root->right)
    {
        getDiameter(root->right, height);
        rightHeight = *height;
    }

    //calculate height of tree
    if(leftHeight > rightHeight)
        *height = leftHeight + 1;
    else
        *height = rightHeight + 1;

    //the diameter of the tree is whichever of these three is the greatest
    int longest = 0;
    if(leftDiameter > longest)      //if the longest path is in the left subtree
        longest = leftDiameter;
    if(rightDiameter > longest)     //if it's in the right subtree
        longest = rightDiameter;
    if(leftHeight + rightHeight + 1 > longest)      //if it goes through the root
        longest = leftHeight + rightHeight + 1;

    return longest;
}
