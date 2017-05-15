#include "main.h"

//determines if the tree has a root-to-leaf path where the sum of all values of the nodes in the path is equal to the given number
int hasSumPath(struct treeNode* root, int sum)
{
    if(root == 0)       //the sum of the path's nodes cannot be equal to "sum" if there are no nodes
        return 0;

    if(!root->left && !root->right)    //if this is a leaf node
    {
        if(root->data == sum)    //if exactly completes the sum
            return 1;
        else
            return 0;
    }

    int leftHasPath = hasSumPath(root->left, sum-root->data);
    int rightHasPath = hasSumPath(root->right, sum-root->data);

    return leftHasPath || rightHasPath;
}
