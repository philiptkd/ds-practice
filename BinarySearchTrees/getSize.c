#include "main.h"

int getSize(struct treeNode* root)
{
    if(root == 0)
        return 0;

    int leftSize = getSize(root->left);
    int rightSize = getSize(root->right);

    return 1 + leftSize + rightSize;
}
