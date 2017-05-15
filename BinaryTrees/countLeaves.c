#include "main.h"

int countLeaves(struct treeNode* root)
{
    if(root == 0)
        return 0;

    if(root->left == 0 && root->right == 0)
        return 1;

    int numLeaves = 0;

    if(root->left)
        numLeaves = numLeaves + countLeaves(root->left);

    if(root->right)
        numLeaves = numLeaves + countLeaves(root->right);

    return numLeaves;
}
