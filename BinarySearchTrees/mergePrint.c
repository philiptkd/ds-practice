#include "main.h"
#include <stdio.h>

//takes 2 BSTs and prints what would be an inorder traversal of their merged BST
void mergePrint(struct treeNode* root1, struct treeNode* root2)
{
    struct treeNode* alreadyPrinted1 = (struct treeNode*)(-1);     //to keep track of relevant nodes already printed in either tree
    struct treeNode* alreadyPrinted2 = (struct treeNode*)(-1);

    struct stackNode* treeStack1 = 0;           //stacks to hold tree nodes for inorder traversal
    struct stackNode* treeStack2 = 0;

    push(&treeStack1, (int)root1);              //push roots onto stacks to initialize
    push(&treeStack2, (int)root2);

    while(treeStack1 || treeStack2)     //while at least one tree has more nodes to print
    {
        struct treeNode* node1 = 0;
        struct treeNode* node2 = 0;

        //pop nodes off of stacks
        if(treeStack1)
            node1 = (struct treeNode*)pop(&treeStack1);
        if(treeStack2)
            node2 = (struct treeNode*)pop(&treeStack2);

        //check if we've already printed one of these nodes. if so, continue
        int continueFlag = 0;
        if(node1 && alreadyPrinted1 == node1->right)    //if we printed this node's right child already,
        {
            alreadyPrinted1 = node1;                            //we already printed this node, too
            continueFlag = 1;
        }
        if(node2 && alreadyPrinted2 == node2->right)
        {
            alreadyPrinted2 = node2;
            continueFlag = 1;
        }
        if(continueFlag)            //if node1 or node2 points to a node we already printed, continue so we can pop off a new node
        {
            if(node1 && alreadyPrinted1 != node1)           //if we haven't already printed this
                push(&treeStack1, (int)node1);       //push it back on for next loop
            if(node2 && alreadyPrinted2 != node2)
                push(&treeStack2, (int)node2);

            continue;
        }

        struct treeNode* toPrint1 = 0;
        struct treeNode* toPrint2 = 0;

        if(node1)
        {
            if(!node1->left || alreadyPrinted1 == node1->left)    //if this node has no left node we can travel to
            {
                toPrint1 = node1;       //store to compare later
            }
            else        //it has a left child we can travel to
            {
                push(&treeStack1, (int)node1);          //get to this node after
                push(&treeStack1, (int)node1->left);        //this node
            }
        }
        if(node2)
        {
            if(!node2->left || alreadyPrinted2 == node2->left)    //if this node has no left node we can travel to
            {
                toPrint2 = node2;       //store to compare later
            }
            else        //it has a left child we can travel to
            {
                push(&treeStack2, (int)node2);          //get to this node after
                push(&treeStack2, (int)node2->left);        //this node
            }
        }

        if(toPrint1 && toPrint2)    //if in both trees, we have reached their next node to print
        {
            if(toPrint1->data < toPrint2->data)
            {
                //see if we need to push right to stack
                if(toPrint1->right)
                    push(&treeStack1, (int)toPrint1->right);

                printf("%d ", toPrint1->data);       //print the lesser value
                alreadyPrinted1 = toPrint1;
                push(&treeStack2, (int)toPrint2);   //push the greater to be popped again next time
            }
            else    //toPrint1->val > toPrint2->val
            {
                //see if we need to push right to stack
                if(toPrint2->right)
                    push(&treeStack2, (int)toPrint2->right);

                printf("%d ", toPrint2->data);       //print the lesser value
                alreadyPrinted2 = toPrint2;
                push(&treeStack1, (int)toPrint1);   //push the greater to be popped again next time
            }
        }
        else            //if only one was ready to print, push it back for next time
        {
            if(node1 && node2)  //if both trees had at least one node left
            {
                if(toPrint1)
                    push(&treeStack1, (int)toPrint1);
                if(toPrint2)
                    push(&treeStack2, (int)toPrint2);
            }
            else if(toPrint1)    //if only tree1 had a node, and it's ready to print
            {
                //see if we need to push right to stack
                if(toPrint1->right)
                    push(&treeStack1, (int)toPrint1->right);

                printf("%d ", toPrint1->data);       //print it
                alreadyPrinted1 = toPrint1;
            }
            else if(toPrint2)
            {
                //see if we need to push right to stack
                if(toPrint2->right)
                    push(&treeStack2, (int)toPrint2->right);

                printf("%d ", toPrint2->data);
                alreadyPrinted2 = toPrint2;
            }
        }
    }
}
