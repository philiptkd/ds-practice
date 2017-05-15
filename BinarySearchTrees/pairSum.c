#include "main.h"
#include <stdio.h>

//finds two nodes in the BST tree given that sum to X
//completes in O(n) time with O(h) extra space
//if the BST is height-balanced, uses O(logn) extra space
void pairSum(struct treeNode* root, int X)
{
    //handle null tree
    if(root == 0)
        return;

    //memory for forward traversal
    struct stackNode* treeStack = 0;
    struct treeNode* alreadyVisited = (struct treeNode*)(-1);
    struct treeNode* next = 0;

    //memory for reverse traversal
    struct stackNode* treeStackR = 0;
    struct treeNode* alreadyVisitedR = (struct treeNode*)(-1);
    struct treeNode* nextR = 0;

    //node pointer for reverse traversal
    struct treeNode* rootR = root;

    //flags for moving forward or back across the tree. both initialized to get the first and last nodes
    int getNextFlag = 1;
    int getNextRFlag = 1;

    do
    {
        if(getNextFlag)
            next = getNextInOrder(&root, &alreadyVisited, &treeStack);
        if(getNextRFlag)
            nextR = getNextInReverse(&rootR, &alreadyVisitedR, &treeStackR);

        if(next->data + nextR->data == X)       //if we've found a pair that sum to X
        {
            if(next->data >= nextR->data)  //to avoid returning pairs of nodes that violate the end while condition
                break;

            printf("%d + %d = %d", next->data, nextR->data, X);
            return;
        }
        else if(next->data + nextR->data < X)   //if the sum is too small, get the next largest node in order
        {
            getNextFlag = 1;
            getNextRFlag = 0;
        }
        else    //if(next->data + nextR->data > X)  //if the sum is too large, get the next smallest node in reverse order
        {
            getNextFlag = 0;
            getNextRFlag = 1;
        }
    }while(next->data < nextR->data);

    //if control reaches here, there was no suitable pair
    printf("No such pair exists.\n");
}
