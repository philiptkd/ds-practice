#include "main.h"
#include <stdio.h>
#include <stdlib.h>

//prints a tree in level order
//I use a queue meant to hold ints because I'm lazy and ints are the same size as pointers on my machine
void printTree(struct treeNode* root)
{
    struct queueNode* q = 0;        //queue to hold tree nodes while printing
    enqueue(&q, (int)root);         //put root on queue
    printf("%d ", root->data);      //print root

    while(!isEmpty(q))
    {
        struct treeNode* tn = (struct treeNode*)dequeue(&q);    //take tree node off of queue

        if(tn->left)        //if it has a node to its left
        {
            enqueue(&q, (int)(tn->left));         //put on queue
            printf("%d ", (tn->left)->data);      //print
        }
        if(tn->right)       //if it has a node to its right
        {
            enqueue(&q, (int)(tn->right));         //put on queue
            printf("%d ", (tn->right)->data);      //print
        }
    }
    printf("\n");
}
