#include "main.h"

int sizeOf(struct treeNode* root)
{
    if(!root)       //to handle empty tree case
        return 0;

    int size = 1;   //size of current node
    if(root->left)  //size of left subtree
    {
        size = size + sizeOf(root->left);
    }
    if(root->right) //size of right subtree
    {
        size = size + sizeOf(root->right);
    }

    return size;
}
