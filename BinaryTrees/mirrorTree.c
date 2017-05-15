#include "main.h"

void mirrorTree(struct treeNode* root)
{
    if(root == 0)   //an empty tree is its own mirror
        return;

    mirrorTree(root->left);
    mirrorTree(root->right);

    struct treeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}
