#include "main.h"

//gets height of a tree, defined as number of nodes on longest path from top to bottom
//uses a queue meant to hold int's because I'm lazy and it works on my machine
int getTreeHeight(struct treeNode* root)
{
    if(!root)           //if there is no tree, it has no height
        { return 0; }

    int height = 0;                     //int to hold height of tree
    struct queueNode* treeQ = 0;        //queue to hold tree nodes
    enqueue(&treeQ, (int)root);         //enqueue first node
    enqueue(&treeQ, -1);                //enqueue a delimiter

    while(!isEmpty(treeQ))
    {
        struct treeNode* tn = (struct treeNode*)dequeue(&treeQ);

        if((int)tn == -1)    //if it was a delimiter
        {
            if(!isEmpty(treeQ))     //if there are more tree nodes to process
            {
                enqueue(&treeQ, -1);    //enqueue another delimiter
            }
            height++;       //increment the height b/c we just finished dequeue-ing a whole level of the tree
        }
        else
        {
            if(tn->left)
            {
                enqueue(&treeQ, (int)tn->left);
            }
            if(tn->right)
            {
                enqueue(&treeQ, (int)tn->right);
            }
        }
    }

    return height;
}
