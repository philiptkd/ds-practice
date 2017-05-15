#include "main.h"

int nodeIsFull(struct treeNode* parent);
int nodeIsEmpty(struct treeNode* parent);

//a complete tree is one with all nodes as far left as possible
    //and with all levels full except possibly the last
//this function traverses a tree using a queue and checks if it is complete
int isCompleteTree(struct treeNode* root)
{
    //an empty tree vacuously meets all requirements for a complete tree
    if(root == 0)
        return 1;

    int notFull = 0;        //once a node is enqueued that is not full, all other nodes must be empty
    struct queueNode* treeQ = 0;    //name of queue to use to traverse tree
    if(!nodeIsFull(root))
        { notFull = 1; }
    enqueue(&treeQ, (int)root);    //pointers to nodes in the tree will be stored in queue (cast as ints b/c it means less work for me)

    while(!isEmpty(treeQ))
    {
        struct treeNode* temp = (struct treeNode*)dequeue(&treeQ);      //get next node from queue
        struct treeNode* left = temp->left;
        struct treeNode* right = temp->right;

        if(right && !left)              //if all nodes are not as far left as possible, the tree is not complete
            { return 0; }

        if(left)
        {
            if(notFull && !nodeIsEmpty(left))       //if we have already seen a node not full, this node having children means the tree is incomplete
                { return 0; }

            if(!nodeIsFull(left))               //see if this node is not full
                { notFull = 1; }

            enqueue(&treeQ, (int)left);         //put in queue to be processed
        }

        if(right)
        {
            if(notFull && !nodeIsEmpty(right))       //if we have already seen a node not full, this node having children means the tree is incomplete
                { return 0; }

            if(!nodeIsFull(right))               //see if this node is not full
                { notFull = 1; }

            enqueue(&treeQ, (int)right);
        }
    }

    return 1;       //if we traversed the whole tree without any problems, it is complete
}

int nodeIsFull(struct treeNode* parent)
{
    if(parent->left && parent->right)
        { return 1; }
    else
        { return 0; }
}

int nodeIsEmpty(struct treeNode* parent)
{
    if(parent->left || parent->right)
        { return 0; }
    else
        { return 1; }
}
