#include "main.h"

void fillTree(struct treeNode* root, int* arr)
{
    struct stackNode* treeStack = 0;
    struct treeNode* alreadyPrinted = (struct treeNode*)(-1);
    int i = 0;  //index of array to fill from

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
            root->data = arr[i];        //put it in the array
            i++;
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
}
