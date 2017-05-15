#include "main.h"

//finds smallest data in BST greater or equal to key
int bstCeil(struct treeNode* root, int key)
{
    struct stackNode* treeStack = 0;
    struct treeNode* alreadyPrinted = (struct treeNode*)(-1);

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
            if(root->data >= key)       //check if ceil of key
                return root->data;

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

    return -1;
}
