#include "main.h"

//takes a tree, a node previously visited, and a stack of nodes to visit
//basically the same as printInOrderWStack(), but incremental
struct treeNode* getNextInOrder(struct treeNode** root, struct treeNode** alreadyVisited, struct stackNode** treeStack)
{
    struct treeNode* nextNode = 0;
    while(*root && !nextNode)
    {
        if((*root)->right == *alreadyVisited)                   //if we have just printed the right subtree
        {
            *alreadyVisited = (*root);
            if(*treeStack)
                (*root) = (struct treeNode*)pop(treeStack);         //go up the tree if we can
            else
                (*root) = 0;
        }
        else if((*root)->left && (*root)->left != *alreadyVisited) //if we haven't yet printed the left subtree
        {
            push(treeStack, (int)(*root));                        //go there first
            (*root) = (*root)->left;
        }
        else                                    //there isn't a left subtree we haven't printed already
        {                                           //and we haven't printed this node already, either
            nextNode = *root;                  //to return
            *alreadyVisited = (*root);

            if((*root)->right)                     //if there is a right subtree
            {
                push(treeStack, (int)(*root));        //go there next
                (*root) = (*root)->right;
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
