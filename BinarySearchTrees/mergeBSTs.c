#include "main.h"

void removeDuplicates(struct listNode* head);

//takes 2 BSTs and combines them into one
//completes in O(m+n) time and O(m+n) extra space
struct treeNode* mergeBSTs(struct treeNode* root1, struct treeNode* root2)
{
    //handle null trees
    if(root1 == 0 && root2 == 0)
        return 0;
    if(root1 == 0)
        return root2;
    if(root2 == 0)
        return root1;

    //sort all nodes into list
    struct listNode* head = bsts2List(root1, root2);

    //remove duplicates from list
    removeDuplicates(head);

    //turn list into balanced BST
    return dll2bst(head);
}
