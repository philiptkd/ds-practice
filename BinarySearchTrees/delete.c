#include <stdlib.h>
#include "main.h"

void delete(struct treeNode** root, int toDelete)
{
    if(*root == 0)      //nothing to delete if the tree is empty
        return;

    //if we need to delete the root of the tree
    if((*root)->data == toDelete)
    {
        if(!(*root)->left && !(*root)->right)   //if it has no children
        {
            free(*root);    //free memory
            *root = 0;      //rename root
        }
        else if((*root)->left && (*root)->right)     //if it has two children
        {
            //find the rightmost node in the left subtree
            struct treeNode* maxOfLeft = (*root)->left;
            while(maxOfLeft->right)
            {
                maxOfLeft = maxOfLeft->right;
            }
            maxOfLeft->right = (*root)->right;  //insert the original right subtree here

            struct treeNode* tmp = *root;
            *root = (*root)->left;      //rename root
            free(tmp);      //free memory
        }
        else if((*root)->left && !(*root)->right)   //if it has only the left child
        {
            struct treeNode* tmp = *root;
            *root = (*root)->left;      //rename root
            free(tmp);      //free memory
        }
        else    //if(!(*root)->left && (*root)->right)  //if it has only the right child
        {
            struct treeNode* tmp = *root;
            *root = (*root)->right;      //rename root
            free(tmp);      //free memory
        }
    }

    //if the node to delete is somewhere in the left subtree
    else if(toDelete < (*root)->data)
    {
        if((*root)->left && (*root)->left->data == toDelete)    //if the left child is to be deleted
        {
            //point the root to the head of the new subtree
            struct treeNode* nodeToDelete = (*root)->left;
            if((*root)->left->left)                         //if the left child has a left subtree,
                (*root)->left = (*root)->left->left;            //point to it as the head of the new subtree
            else if((*root)->left->right)
                (*root)->left = (*root)->left->right;       //else point to any right subtree
            else
                (*root)->left = 0;                          //else point to null

            delete(&nodeToDelete, toDelete);
        }
        else    //the left child is not to be deleted
        {
            delete(&((*root)->left), toDelete);
        }
    }

    //if the node to delete is somewhere in the right subtree
    else if(toDelete > (*root)->data)
    {
        if((*root)->right && (*root)->right->data == toDelete)    //if the right child is to be deleted
        {
            //point the root to the head of the new subtree
            struct treeNode* nodeToDelete = (*root)->right;
            if((*root)->right->left)                         //if the right child has a left subtree,
                (*root)->right = (*root)->right->left;            //point to it as the head of the new subtree
            else if((*root)->right->right)
                (*root)->right = (*root)->right->right;       //else point to any right subtree
            else
                (*root)->right = 0;                          //else point to null

            delete(&nodeToDelete, toDelete);
        }
        else    //the right child is not to be deleted
        {
            delete(&((*root)->right), toDelete);
        }
    }
}
