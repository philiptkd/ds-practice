#include "main.h"

int areSameTree(struct treeNode* root1, struct treeNode* root2)
{
    if(root1 == 0 && root2 == 0)    //two empty trees are identical
        return 1;
    else if(root1 == 0 || root2 == 0)   //if only one exists, then the two trees are not identical
        return 0;

    //if we reach here, both root treeNodes exist
    if(root1->data != root2->data)      //nodes in the same position with different values are not in identical trees
        return 0;

    int leftHalvesAreSame = areSameTree(root1->left, root2->left);
    int rightHalvesAreSame = areSameTree(root1->right, root2->right);

    if(leftHalvesAreSame && rightHalvesAreSame)
        return 1;
    else
        return 0;
}
