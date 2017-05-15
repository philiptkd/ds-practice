#include "main.h"

//searches a BST for a value
//returns a pointer to the node with the given value
//returns a null pointer if the value was not found
struct treeNode* search(struct treeNode* root, int toFind)
{
    if(root == 0 || root->data == toFind)
        return root;

    if(toFind < root->data)                 //if value is less
        return search(root->left, toFind);      //search left subtree

    if(toFind > root->data)                 //if value is greater
        return search(root->right, toFind);     //search right subtree

    return 0;   //the value was not found
}
