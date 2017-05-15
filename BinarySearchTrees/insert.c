#include <stdlib.h>
#include "main.h"

//inserts a value into a BST.
//returns a pointer to the new node
struct treeNode* insert(struct treeNode** root, int toInsert)
{
    if(*root == 0)       //if the given tree was empty
    {
        //make a new tree with this node being its only node
        struct treeNode* node = newNode(toInsert);
        *root = node;
        return node;
    }

    if(toInsert == (*root)->data)  //if the value is already in the tree
    {
        return *root;       //return a pointer to it
    }

    if(toInsert < (*root)->data)    //if the value is less than current node
    {
        if((*root)->left)                           //if the current node has a left subtree
            return insert(&((*root)->left), toInsert);     //insert the new value into it

        //else if the current node doesn't have a left subtree
        (*root)->left = newNode(toInsert);      //insert the new node here
        return (*root)->left;           //return the location of the new node
    }

    if(toInsert > (*root)->data)    //if the value is greater than current node
    {
        if((*root)->right)                           //if the current node has a right subtree
            return insert(&((*root)->right), toInsert);     //insert the new value into it

        //else if the current node doesn't have a right subtree
        (*root)->right = newNode(toInsert);      //insert the new node here
        return (*root)->right;           //return the location of the new node
    }

    return 0;   //should never be reached
}
