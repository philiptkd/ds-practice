#include "main.h"

struct treeNode* dll2bstRecur(struct listNode** head, int start, int end);

//takes a sorted doubly-linked list and returns a height-balanced BST
//completes in O(n) time by incrementing head and traveling the whole list once (after getting the length)
//uses O(h) extra space in the call stack
struct treeNode* dll2bst(struct listNode* head)
{
    if(head == 0)   //an empty dll is the same as an empty bst
        return 0;

    int len = 1;
    struct listNode* n = head;
    while(n->next)       //get the length of the list
    {
        len++;
        n = n->next;
    }
    if(len == 1)    //a single node-dll is the same as a single-node bst
        return (struct treeNode*)head;

    int rootIndex = len/2;

    struct treeNode* leftRoot = 0;
    struct treeNode* rightRoot = 0;

    //get root of left subtree
    leftRoot = dll2bstRecur(&head, 0, rootIndex-1);

    //head now points to the root of the whole tree
    struct treeNode* root = (struct treeNode*)head;
    head = head->next;

    //get root of the right subtree, if there is one
    if(rootIndex+1 < len)
        rightRoot = dll2bstRecur(&head, rootIndex+1, len-1);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

struct treeNode* dll2bstRecur(struct listNode** head, int start, int end)
{
    int len = end - start + 1;  //length of section of list
    if(len == 1)    //if this list section is one element long, it is a leaf
    {
        struct treeNode* tmp = (struct treeNode*)(*head);
        *head = (*head)->next;      //go to next item in list
        tmp->left = 0;
        tmp->right = 0;
        return tmp;
    }

    int rootIndex = len/2 + start;

    struct treeNode* leftRoot = 0;
    struct treeNode* rightRoot = 0;

    //get root of left subtree
    leftRoot = dll2bstRecur(head, start, rootIndex-1);

    //head now points to the root of the whole tree
    struct treeNode* root = (struct treeNode*)(*head);
    *head = (*head)->next;

    //get root of the right subtree, if there is one
    if(rootIndex+1 <= end)
        rightRoot = dll2bstRecur(head, rootIndex+1, end);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}
