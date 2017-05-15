#include "main.h"

//two nodes' lowest common ancestor is the node furthest from the root with both given nodes as descendants
//we allow a node to be its own descendant
//assumes tree is BST and that both n1 and n2 are in the tree
//completes in O(h) time and O(h) extra space on the call stack, where h is the height of the tree
//could be done with O(1) extra space if done iteratively (like in a while loop that changes the current working node at the end)

int lowestCommonAncestor(struct treeNode* root, int n1, int n2)
{
    if(root == 0)       //if this is true, there was probably an invalid input
        return -1;

    int rd = root->data;

    if((n1<=rd && n2>=rd)||(n1>=rd && n2<=rd))      //if the two values are on opposite sides of the tree
    {
        return root->data;      //their lowest common ancestor must be the root
    }
    else if(n1<rd && n2<rd)     //the previous 'if' handles cases where n1=root or n2=root, so we can use strict inequalities here
    {
        return lowestCommonAncestor(root->left, n1, n2);
    }
    else    //if (n1>rd && n2>rd)
    {
        return lowestCommonAncestor(root->right, n1, n2);
    }
}
