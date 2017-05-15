#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct fibTreeNode* fibGetMin(struct fibHeap* F)
{
    if(F == 0)
        return 0;

    return F->minNode;
}

//concatenates the circular doubly-linked lists of each heap's tree roots
//firstF...lastF<->firstG...lastG<->firstF
void fibMerge(struct fibHeap* F, struct fibHeap* G)
{
    struct fibTreeNode* firstF = F->leftRoot;
    struct fibTreeNode* lastF = firstF->leftSibling;
    struct fibTreeNode* firstG = G->leftRoot;
    struct fibTreeNode* lastG = firstG->leftSibling;

    lastF->rightSibling = firstG;
    firstG->leftSibling = lastF;
    lastG->rightSibling = firstF;
    firstF->leftSibling = lastG;

    if(G->maxHeight > F->maxHeight)
        F->maxHeight = G->maxHeight;

    if(G->minNode->data < F->minNode->data)
        F->minNode = G->minNode;
}

void fibInsert(struct fibHeap* F, int key)
{
    struct fibHeap* G = newFibHeap(key, 0);
    fibMerge(F, G);
    free(G);    //frees the memory allocated to hold heap pointers
}

struct fibHeap* newFibHeap(int key, int maxHeight)
{
    if(maxHeight < 0)
        maxHeight = 0;

    struct fibHeap* G = (struct fibHeap*)malloc(sizeof(struct fibHeap));                //allocate memory for heap pointers
    struct fibTreeNode* node = (struct fibTreeNode*)malloc(sizeof(struct fibTreeNode)); //allocate memory for the one node

    //initialize node values
    node->data = key;
    node->leftChild = 0;
    node->leftSibling = node;
    node->rightSibling = node;

    //initialize heap values
    G->leftRoot = node;
    G->minNode = node;
    G->maxHeight = maxHeight;

    return G;
}

int fibExtractMin(struct fibHeap* F)
{
    //find min node
    struct fibTreeNode* minNode = fibGetMin(F);

    if(minNode == 0)            //handle case of empty heap
        return INT_MAX;

    //save value
    int ret = minNode->data;

    //remove min node, making its children roots of trees
    fibRemoveMin(F, minNode);

    //combine trees of same degree
    fibCombineTrees(F);

    //update min pointer
    fibUpdateMin(F);

    return ret;
}

void fibCombineTrees(struct fibHeap* F)
{
    if(F == 0 || F->leftRoot == 0)      //if the heap is empty
        return;

    //create an array of pointers to keep track of heights of trees
    struct fibTreeNode** heightArr = (struct fibTreeNode**)malloc((F->maxHeight + 1)*sizeof(struct fibTreeNode*));
    int i;
    for(i=0; i<F->maxHeight+1; i++)     //initialize array to null pointers
    {
        heightArr[i] = 0;
    }

    struct fibTreeNode* current = F->leftRoot;
    struct fibTreeNode* next = current->rightSibling;

    heightArr[fibGetHeight(current)] = current;     //store leftRoot's height
    while(next != F->leftRoot)     //for every other root in the heap
    {
        current = next;
        next = current->rightSibling;

        int height = fibGetHeight(current);
        if(heightArr[height] == 0)          //if this is the first tree encountered with this height
        {
            heightArr[height] = current;        //save it in the array and move on
        }
        else    //there is another tree with this height
        {
            struct fibTreeNode* other = heightArr[height];

            if(current->data < other->data)     //we want the trees to maintain the minHeap property
            {
                makeXChildOfY(other, current, F, height);

                //update height array
                heightArr[height] = 0;
                if(heightArr[height + 1] == 0)
                    heightArr[height + 1] = current;
                else
                    next = current;     //so that we can revisit this node in the next loop
            }
            else
            {
                makeXChildOfY(current, other, F, height);

                //update height array
                heightArr[height] = 0;
                if(heightArr[height + 1] == 0)
                    heightArr[height + 1] = other;
                else
                    next = other;     //so that we can revisit this node in the next loop
            }
        }
    }
}

void makeXChildOfY(struct fibTreeNode* newChild, struct fibTreeNode* newParent, struct fibHeap* F, int height)
{
    struct fibTreeNode* leftOfNewChild = newChild->leftSibling;
    struct fibTreeNode* rightOfNewChild = newChild->rightSibling;

    //update leftRoot pointer if necessary
    if(newChild == F->leftRoot)
        F->leftRoot = rightOfNewChild;

    //leftOfNewChild<->rightOfNewChild
    leftOfNewChild->rightSibling = rightOfNewChild;
    rightOfNewChild->leftSibling = leftOfNewChild;

    if(height > 0)      //if newParent has children
    {
        struct fibTreeNode* leftChildOfNewParent = newParent->leftChild;
        struct fibTreeNode* rightChildOfNewParent = leftChildOfNewParent->leftSibling;

        //rightChildOfNewParent<->newChild<->leftChildOfNewParent
        rightChildOfNewParent->rightSibling = newChild;
        newChild->leftSibling = rightChildOfNewParent;
        newChild->rightSibling = leftChildOfNewParent;
        leftChildOfNewParent->leftSibling = newChild;
    }
    else    //newParent has no children. prepare newChild to be an only child
    {
        //newChild<->newChild
        newChild->leftSibling = newChild;
        newChild->rightSibling = newChild;
    }

    //make newChild the leftChild of newParent
    newParent->leftChild = newChild;
}

int fibGetHeight(struct fibTreeNode* root)
{
    int height = -1;

    while(root)
    {
        height = height + 1;
        root = root->leftChild;
    }

    return height;
}

void fibUpdateMin(struct fibHeap* F)
{
    struct fibTreeNode* smallest = F->leftRoot;
    struct fibTreeNode* node = F->leftRoot;
    while(node->rightSibling != F->leftRoot)    //visit every tree root
    {
        node = node->rightSibling;
        if(node->data < smallest->data)
            smallest = node;
    }
    F->minNode = smallest;
}

void fibRemoveMin(struct fibHeap* F, struct fibTreeNode* minNode)
{
    struct fibTreeNode* leftOfMin = minNode->leftSibling;
    struct fibTreeNode* rightOfMin = minNode->rightSibling;
    if(minNode->leftChild)              //if minNode had children
    {
        struct fibTreeNode* leftChild = minNode->leftChild;
        struct fibTreeNode* rightChild = leftChild->leftSibling;

        if(minNode == leftOfMin)    //if minNode was the only tree root
        {
            //don't do anything
        }
        else    //if minNode wasn't the only tree root
        {
            //leftOfMin<->leftChild...rightChild<->rightOfMin
            leftOfMin->rightSibling = leftChild;
            leftChild->leftSibling = leftOfMin;
            rightChild->rightSibling = rightOfMin;
            rightOfMin->leftSibling = rightChild;
        }

        if(F->leftRoot == minNode)          //update the heap's leftRoot pointer if we have to
            F->leftRoot = leftChild;
    }
    else        //if it didn't have children
    {
        //leftOfMin<->rightOfMin
        leftOfMin->rightSibling = rightOfMin;
        rightOfMin->leftSibling = leftOfMin;

        if(F->leftRoot == minNode)          //update the heap's leftRoot pointer if we have to
            F->leftRoot = rightOfMin;
    }

    free(minNode);
}

void printFibHeap(struct fibTreeNode* leftTree)
{
    if(leftTree == 0)
        return;

    struct fibTreeNode* node = leftTree;

    do
    {
        if(node->leftChild)
            printFibHeap(node->leftChild);
        printf("%d ", node->data);
        node = node->rightSibling;
    }while(node != leftTree);
}
