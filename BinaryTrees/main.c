#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int checkChildrenSum(struct treeNode* root);
void convert2ChildrenSum(struct treeNode* root);
int getDiameter(struct treeNode* root, int* height);
int isHeightBalanced(struct treeNode* root, int* height);
int hasSumPath(struct treeNode* root, int sum);

int main()
{
    //just a tree to test with
    struct treeNode* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    int i;
    for(i=0; i<30; i++)
    {
        printf("%d: %d\n", i, hasSumPath(root, i));
    }


    return 0;
    }
