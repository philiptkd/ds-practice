#include "main.h"

int heightOf(struct treeNode* root)
{
    if(root == 0)
        return 0;

    int leftHeight = 1 + heightOf(root->left);
    int rightHeight = 1 + heightOf(root->right);

    if(leftHeight >= rightHeight)
        return leftHeight;
    else
        return rightHeight;
}
