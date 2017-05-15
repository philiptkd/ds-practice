#include "main.h"

//finds largest data in BST less or equal to key
int bstFloor(struct treeNode* root, int key)
{
    struct stackNode* treeStack = 0;
    struct treeNode* alreadyPrinted = (struct treeNode*)(-1);
    struct treeNode* prev = 0;

    while(root)
    {
        if(root->right == alreadyPrinted)                   //if we have just printed the right subtree
        {
            alreadyPrinted = root;
            if(treeStack)
                root = (struct treeNode*)pop(&treeStack);         //go up the tree if we can
            else
                root = 0;
        }
        else if(root->left && root->left != alreadyPrinted) //if we haven't yet printed the left subtree
        {
            push(&treeStack, (int)root);                        //go there first
            root = root->left;
        }
        else                                    //there isn't a left subtree we haven't printed already
        {                                           //and we haven't printed this node already, either
            if(root->data == key)       //check if floor of key
            {
                return root->data;
            }
            else if(root->data > key)   //if this node's data is too big, the previous one is the one we want
            {
                if(prev)
                    return prev->data;
                else                    //if this was the first node and it was too big, there is no node small enough
                    return -1;
            }

            prev = root;
            alreadyPrinted = root;

            if(root->right)                     //if there is a right subtree
            {
                push(&treeStack, (int)root);        //go there next
                root = root->right;
            }
            else
            {
                if(treeStack)
                    root = (struct treeNode*)pop(&treeStack);   //if there's not, go back up the tree
                else
                    root = 0;
            }
        }
    }

    return prev->data;
}
