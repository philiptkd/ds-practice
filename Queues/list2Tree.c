#include "main.h"
#include <stdlib.h>

//converts a singly linked list to a complete tree
//see isCompleteTree() for definition of a complete tree
//I use a queue meant to hold ints because I'm lazy and ints are the same size as pointers on my machine
//assumes there is at least one element in the list
struct treeNode* list2Tree(struct listNode* head)
{
    struct queueNode* q = 0;        //queue to hold nodes while converting to tree

    //initialize tree by defining the root
    struct treeNode* root = (struct treeNode*)malloc(sizeof(struct treeNode));
    root->data = head->data;
    root->left = 0;
    root->right = 0;

    //put root on queue and move down the list
    enqueue(&q, (int)root);
    head = head->next;

    //while the queue is not empty
    while(!isEmpty(q))
    {
        //get next node to connect the rest of the tree to
        struct treeNode* tn = (struct treeNode*)dequeue(&q);

        if(!head)           //if there are no more elements in the list to put on the tree
            { break; }

        //create left treeNode
        struct treeNode* leftNode = (struct treeNode*)malloc(sizeof(struct treeNode));

        //initialize left tree node
        leftNode->data = head->data;
        leftNode->left = 0;
        leftNode->right = 0;

        tn->left = leftNode;        //connect left node to tree
        enqueue(&q, (int)leftNode); //put on queue to find its leaves later

        head = head->next;          //go to next element on the list
        if(!head)           //if there are no more elements in the list to put on the tree
            { break; }

        struct treeNode* rightNode = (struct treeNode*)malloc(sizeof(struct treeNode));

        //initialize right tree node
        rightNode->data = head->data;
        rightNode->left = 0;
        rightNode->right = 0;

        tn->right = rightNode;        //connect right node to tree
        enqueue(&q, (int)rightNode); //put on queue to find its leaves later

        head = head->next;          //go to next element on the list
    }

    return root;
}
