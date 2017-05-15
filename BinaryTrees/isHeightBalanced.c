#include "main.h"

//we define a height-balanced tree to be a tree with left- and right-subtrees that are each balanced and that
    //differ in height by at most 1
//when first called, *height can be any value
//completes in O(n) time and O(1) extra space
int isHeightBalanced(struct treeNode* root, int* height)
{
    if(root == 0)       //an empty tree is balanced
    {
        *height = 0;
        return 1;
    }
    if(!root->left && !root->right)     //a single node is a balanced tree
    {
        *height = 1;
        return 1;
    }

    //check if left subtree is balanced and get its height
    int isLeftBalanced = isHeightBalanced(root->left, height);
    int leftHeight = *height;

    //check if right subtree is balanced and get its height
    int isRightBalanced = isHeightBalanced(root->right, height);
    int rightHeight = *height;

    //if either were not height-balanced, the whole tree is also no
    if(!isLeftBalanced || !isRightBalanced)
        return 0;

    //if we reach here, both left- and right-subtrees are height-balanced
    //check if subtrees' heights are within 1 of each other
    if(leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1)
        return 0;

    //this tree is height-balanced
    //calculate height of tree
    if(leftHeight > rightHeight)
        *height = leftHeight + 1;
    else
        *height = rightHeight + 1;

    return 1;
}
