#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct binomialTreeNode* unionBinHeaps(struct binomialTreeNode* H, struct binomialTreeNode* G)
{
    //handle cases of empty heaps
    if(H == 0)
        return G;
    if(G == 0)
        return H;

    //merge heaps in non-decreasing order of heights
    struct binomialTreeNode* I = mergeHeaps(H, G);

    //combine trees with equal heights
    struct binomialTreeNode* current = I;
    struct binomialTreeNode* next = current->rightSibling;
    struct binomialTreeNode* prev = 0;
    while(next)
    {
        int currentHeight = getHeight(current);
        int nextHeight = getHeight(next);

        if(currentHeight != nextHeight)     //if the heights are not the same, move on. no need to combine these trees
        {
            prev = current;
            current = next;
            next = next->rightSibling;
        }
        else    //if the heights are the same
        {
            if(next->rightSibling && getHeight(next->rightSibling) == nextHeight)   //if there are three trees with the same height
            {
                //move on. the two rightmost trees will be combined
                prev = current;
                current = next;
                next = next->rightSibling;
            }
            else    //if these are the only two trees with this height
            {
                if(current->data > next->data)  //if current's root key is larger, make current the new leftChild of next
                {
                    current->rightSibling = next->leftChild;
                    next->leftChild = current;

                    if(prev)                            //if current has a leftSibling
                        prev->rightSibling = next;          //update its pointer
                    else
                        I = next;                       //otherwise, update pointer to leftmost tree in heap

                    //prev need not be updated
                    current = next;
                    next = next->rightSibling;
                }
                else    //if next's root key is larger, make next the new leftChild of current
                {
                    current->rightSibling = next->rightSibling;
                    next->rightSibling = current->leftChild;
                    current->leftChild = next;

                    //prev need not be updated
                    //current need not be updated
                    next = current->rightSibling;
                }
            }
        }
    }

    return I;
}

//creates one heap from two. sorts trees in new heap in order of increasing height
//assumes the trees in each heap are already sorted
struct binomialTreeNode* mergeHeaps(struct binomialTreeNode* H, struct binomialTreeNode* G)
{
    if(H == 0)      //handle cases of empty heap
        return G;
    if(G == 0)
        return H;

    int heightH = getHeight(H);
    int heightG = getHeight(G);

    struct binomialTreeNode* I; //to be the merged heap

    //choose from which heap the leftmost tree will come
    if(heightH < heightG)
    {
        I = H;
        H = H->rightSibling;
        heightH = getHeight(H);
    }
    else
    {
        I = G;
        G = G->rightSibling;
        heightG = getHeight(G);
    }

    struct binomialTreeNode* ret = I;   //save leftmost tree pointer to return later

    while(H || G)
    {
        if(H == 0)      //if heap H is empty, get next tree from G
        {
            I->rightSibling = G;
            I = I->rightSibling;
            G = G->rightSibling;
            heightG = getHeight(G);
        }
        else if(G == 0) //if heap G is empty, get next tree from H
        {
            I->rightSibling = H;
            I = I->rightSibling;
            H = H->rightSibling;
            heightH = getHeight(H);
        }
        else    //if neither are empty, we must compare their heights
        {
            if(heightH < heightG)   //if heap H is shorter, draw from it for the next tree in heap I
            {
                I->rightSibling = H;
                I = I->rightSibling;
                H = H->rightSibling;
                heightH = getHeight(H);
            }
            else
            {
                I->rightSibling = G;
                I = I->rightSibling;
                G = G->rightSibling;
                heightG = getHeight(G);
            }
        }
    }

    return ret;
}

int getHeight(struct binomialTreeNode* H)
{
    if(H == 0)
        return -1;

    int height = 0;

    while(H->leftChild)
    {
        height = height + 1;
        H = H->leftChild;
    }

    return height;
}

void binInsert(struct binomialTreeNode** H, int k)
{
    struct binomialTreeNode* littleHeap = createNewHeap(k);     //creates a heap with just this element in it
    struct binomialTreeNode* I = unionBinHeaps(*H, littleHeap);        //combines the two heaps

    if(I != *H)
        *H = I;
}

struct binomialTreeNode* createNewHeap(int k)
{
    struct binomialTreeNode* H = (struct binomialTreeNode*)malloc(sizeof(struct binomialTreeNode));
    H->data = k;
    H->leftChild = 0;
    H->rightSibling = 0;

    return H;
}

//gets the minimum node in the binomial heap pointed to by H
//takes O(logn) time
struct binomialTreeNode* binGetMin(struct binomialTreeNode* H)
{
    struct binomialTreeNode* smallestNode = 0;
    int smallest = INT_MAX;

    while(H)
    {
        if(H->data < smallest)
        {
            smallest = H->data;
            smallestNode = H;
        }

        H = H->rightSibling;
    }

    return smallestNode;
}

int binExtractMin(struct binomialTreeNode** H)
{
    struct binomialTreeNode* smallestNode = binGetMin(*H);      //get the node with the smallest key
    if(smallestNode == 0)                                       //if H is an empty heap
        return -1;

    int smallest = smallestNode->data;                          //save the key for later

    //remove this entire tree from the heap H
    removeTree(H, smallestNode);

    //the subtrees of smallestNode form a heap
    struct binomialTreeNode* newHeap = smallestNode->leftChild;

    //reorder trees in newHeap to be in order of increasing height
    reverseHeap(&newHeap);

    //call union() on the new heap and the modified H
    struct binomialTreeNode* I = unionBinHeaps(*H, newHeap);
    if(I != *H)
        *H = I;

    //free memory of smallestNode
    free(smallestNode);

    return smallest;
}

void reverseHeap(struct binomialTreeNode** H)
{
    if(*H == 0)
        return;

    //pointers to traverse the heap
    struct binomialTreeNode* current = *H;      //start at left side
    struct binomialTreeNode* next = current->rightSibling;
    struct binomialTreeNode* prev = 0;

    current->rightSibling = prev;   //the leftmost tree will now be the rightmost

    while(next) //while there is another tree
    {
        //update the pointers
        prev = current;
        current = next;
        next = current->rightSibling;

        //reverse direction of this rightSibling pointer
        current->rightSibling = prev;
    }
    *H = current;
}

void removeTree(struct binomialTreeNode** H, struct binomialTreeNode* treeNode)
{
    if(treeNode == *H)      //if this tree is the leftmost tree in H
    {
        *H = (*H)->rightSibling;    //if it was the ONLY tree in H, rightSibling will be a null pointer, and H will be empty
    }
    else        //if this tree has a left sibling
    {
        struct binomialTreeNode* prev = *H;
        while(prev->rightSibling != treeNode)   //find the left sibling
        {
            prev = prev->rightSibling;
        }
        prev->rightSibling = treeNode->rightSibling;        //if it was the rightmost tree in H, rightSibling will be a null pointer
    }
}

void printBinomialHeap(struct binomialTreeNode* H)
{
    while(H)
    {
        if(H->leftChild)
            printBinomialHeap(H->leftChild);
        printf("%d ", H->data);
        H = H->rightSibling;
    }
}
