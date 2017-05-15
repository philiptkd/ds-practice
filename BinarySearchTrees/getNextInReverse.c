#include "main.h"

//takes a tree, a node previously visited, and a stack of nodes to visit
//exactly the same as getNextInOrder(), but done in reverse order
struct treeNode* getNextInReverse(struct treeNode** root, struct treeNode** alreadyVisited, struct stackNode** treeStack)
{
    struct treeNode* nextNode = 0;
    while(*root && !nextNode)
    {
        if((*root)->left == *alreadyVisited)                   //if we have just printed the left subtree
        {
            *alreadyVisited = (*root);
            if(*treeStack)
                (*root) = (struct treeNode*)pop(treeStack);         //go up the tree if we can
            else
                (*root) = 0;
        }
        else if((*root)->right && (*root)->right != *alreadyVisited) //if we haven't yet printed the right subtree
        {
            push(treeStack, (int)(*root));                        //go there first
            (*root) = (*root)->right;
        }
        else                                    //there isn't a right subtree we haven't printed already
        {                                           //and we haven't printed this node already, either
            nextNode = *root;                  //to return
            *alreadyVisited = (*root);

            if((*root)->left)                     //if there is a right subtree
            {
                push(treeStack, (int)(*root));        //go there next
                (*root) = (*root)->left;
            }
            else
            {
                if(*treeStack)
                    (*root) = (struct treeNode*)pop(treeStack);   //if there's not, go back up the tree
                else
                    (*root) = 0;
            }
        }
    }
    return nextNode;
}
