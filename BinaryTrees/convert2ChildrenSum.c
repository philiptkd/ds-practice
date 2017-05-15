#include "main.h"

void levelOrderChildrenSum(struct treeNode* root);
void postOrderChildrenSum(struct treeNode* root);

//traverses the tree twice to modify the tree so that it has the children sum property
    //i.e., every node's value is the sum of its children's values, if it has children
//the only constraint is that node values are only increased, not decreased
//on the first traversal, it ensures left+right >= mid
    //then on the second, it increases mids so that left+right = mid
//each half--and therefore the whole function--uses O(n) time and O(n) extra space
void convert2ChildrenSum(struct treeNode* root)
{
    //first traversal is level-order
    levelOrderChildrenSum(root);

    //second traversal, to ensure equality, is post-order
    postOrderChildrenSum(root);
}

void levelOrderChildrenSum(struct treeNode* root)
{
    struct queueNode* q = 0;        //queue to hold tree nodes for level-order traversal
    enqueue(&q, (int)root);

    //first traversal to ensure sum of children's values are >= parents' values
    while(!isEmpty(q))
    {
        struct treeNode* node = (struct treeNode*)dequeue(&q);

        if(node->left && node->right)   //if this node has two children
        {
            int sum = node->left->data + node->right->data;
            if(sum < node->data)                                    //if the parent's value is greater than the sum of its children's
                node->left->data = node->left->data + (node->data - sum);   //increase the sum by increasing the left child's value
        }
        else if(node->left && !node->right) //if this node has only the left child
        {
            if(node->left->data < node->data)
                node->left->data = node->data;     //ensure its value <= left child's value
        }
        else if(!node->left && node->right) //if this node has only a right child
        {
            if(node->right->data < node->data)
                node->right->data = node->data;     //ensure its value <= right child's value
        }

        //enqueue the children
        if(node->left)
            enqueue(&q, (int)node->left);
        if(node->right)
            enqueue(&q, (int)node->right);
    }
}

void postOrderChildrenSum(struct treeNode* root)
{
    if(root->left)                          //do for left child
        postOrderChildrenSum(root->left);

    if(root->right)                         //do for right child
        postOrderChildrenSum(root->right);

    //do for root
    if(root->left && root->right)       //if it has two children
    {
        int sum = root->left->data + root->right->data;
        root->data = sum;
    }
    else if(root->left && !root->right) //if it has only a left child
    {
        root->data = root->left->data;
    }
    else if(!root->left && root->right) //if it has only a right child
    {
        root->data = root->right->data;
    }
}
