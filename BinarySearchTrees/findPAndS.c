#include "main.h"
#include <stdio.h>

//finds the inorder predecessor and successor in a BST of a given key
//if the key is not in the tree, finds what p and s would be if it were inserted
//completes in O(h) time and O(h) extra space on the call stack, where h is the height of the tree
//could be done with O(1) extra space if done iteratively (like in a while loop that changes the current working node at the end)

void findPreAndSuc(struct treeNode* root, int key, struct treeNode** p, struct treeNode** s);

//this is a wrapper to avoid the user having know how to initialize parameters
void findPAndS(struct treeNode* root, int key)
{
    struct treeNode* p = 0;
    struct treeNode* s = 0;
    findPreAndSuc(root, key, &p, &s);

    if(p && s)
        printf("Predecessor: %d\nSuccessor: %d\n\n", p->data, s->data);
    else if(p && !s)
        printf("Predecessor: %d\nSuccessor: none\n\n", p->data);
    else if(!p && s)
        printf("Predecessor: none\nSuccessor: %d\n\n", s->data);
    else //if (!p && !s)
        printf("Predecessor: none\nSuccessor: none\n\n");
}

void findPreAndSuc(struct treeNode* root, int key, struct treeNode** p, struct treeNode** s)
{
    if(root == 0)   //nothing to find if the tree is empty
        return;

    if(key == root->data)       //if the root has the key we want
    {
        if(root->left)              //its predecessor is the rightmost node of its left subtree
        {
            struct treeNode* predecessor = root->left;
            while(predecessor->right)
            {
                predecessor = predecessor->right;
            }
            *p = predecessor;
        }

        if(root->right)             //its successor is the leftmost node of its right subtree
        {
            struct treeNode* successor = root->right;
            while(successor->left)
            {
                successor = successor->left;
            }
            *s = successor;
        }
        return;
    }

    else if(key < root->data)   //if the key is less than the root's value
    {
        *s = root;  //the root comes after the given key in order
        findPreAndSuc(root->left, key, p, s);
    }

    else if(key > root->data)   //if the key is greater than the root's value
    {
        *p = root;  //the root comes before the given key in order
        findPreAndSuc(root->right, key, p, s);
    }
}
