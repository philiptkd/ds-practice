#include "main.h"

//returns 1 if for every node, its value is the sum of its children's values
//null children are regarded as having 0 value
//leaves can have any value
int checkChildrenSum(struct treeNode* root)
{
    if(root == 0)   //an empty tree vacuously meets the requirements
        return 1;

    if(root->left == 0 && root->right == 0)     //a leaf can have any value
        return 1;

    int sum = 0;
    if(root->left)
    {
        sum = sum + root->left->data;
    }
    if(root->right)
    {
        sum = sum + root->right->data;
    }
    if(sum != root->data)               //if the root's value is not equal to the sum of its children's values
        return 0;

    if(checkChildrenSum(root->left) && checkChildrenSum(root->right))   //return true if true for all nodes on the left and on the right
        return 1;
    else
        return 0;
}
