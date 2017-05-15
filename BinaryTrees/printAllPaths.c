#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int sizeOf(struct treeNode* root);
void printPaths(struct treeNode* root, int* arr, int pathLen);

//prints a path from the root and to every leaf
void printAllPaths(struct treeNode* root)
{
    if(root == 0)
        return;

    int maxLen = sizeOf(root);      //in a completely skewed tree, the path to its one leaf covers all nodes
    int* arr = (int*)malloc(maxLen*sizeof(int));    //allocate memory for array to hold path
    printPaths(root, arr, 0);   //print
}

//assumes root!=0
void printPaths(struct treeNode* root, int* arr, int pathLen)
{
    if(root->left == 0 && root->right == 0)     //if this node is a leaf
    {
        int i;
        for(i=0;i<pathLen;i++)      //print the path until this node
        {
            printf("%d ", arr[i]);
        }
        printf("%d\n", root->data);     //print this node
    }

    else        //if it's not a leaf
    {
        arr[pathLen] = root->data;

        if(root->left)
        {
            printPaths(root->left, arr, pathLen+1);
        }
        if(root->right)
        {
            printPaths(root->right, arr, pathLen+1);
        }
    }


}
