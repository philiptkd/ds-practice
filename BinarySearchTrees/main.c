#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    struct treeNode* root1 = newNode(10);
    root1->left = newNode(30);
    root1->left->left = newNode(20);
    root1->right = newNode(15);
    root1->right->right = newNode(5);

    struct treeNode* root2 = newNode(25);
    root2->left = newNode(5);
    root2->left->right = newNode(20);
    root2->right = newNode(10);
    root2->right->left = newNode(40);

    tree2bst(root1);
    tree2bst(root2);

    struct treeNode* root = mergeBSTs(root1, root2);
    printTreeInOrder(root);

    return 0;
}

