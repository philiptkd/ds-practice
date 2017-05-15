//just like printTreeLevelOrder() but prints each level on a separate line

#include "main.h"
#include <stdio.h>

void printLevels(struct treeNode* root)
{
    if(!root)       //an empty tree doesn't need printing
        return;

    struct queueNode* q = 0;    //queue for tree nodes
    enqueue(&q, (int)root);     //enqueue the root
    enqueue(&q, -1);            //enqueue a delimiter to mark the end of a level
    printf("%d\n", root->data); //the root is always on its own level

    while(!isEmpty(q))
    {
        struct treeNode* node = (struct treeNode*)dequeue(&q);

        //if the node was a delimiter, we finished printing a level
        if((int)node == -1)
        {
            printf("\n");       //print a new line

            if(!isEmpty(q))     //if there is another level to print
                enqueue(&q, -1);    //enqueue another delimiter

            continue;
        }

        //enqueue and print the left node
        if(node->left)
        {
            enqueue(&q, (int)node->left);
            printf("%d ", node->left->data);
        }

        //enqueue and print the right side
        if(node->right)
        {
            enqueue(&q, (int)node->right);
            printf("%d ", node->right->data);
        }
    }
}
