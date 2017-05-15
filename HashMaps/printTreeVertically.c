#include "main.h"
#include <stdio.h>
#include <stdlib.h>

//wrapper for recursive function with more parameters
void printTreeVertically(struct treeNode* root)
{
    //create hash table of arbitrary size 20
    struct hMap* m = newHashMap(20);

    //to store in hash table
    printTreeVerticallyRecur(root, 0, m);

    //print from hash table
    //while traversing the table, only print if stored hash input is equal to desired horizDist
}

//use preorder tree traversal to visit all nodes
//for each node, store its key in a hashmap
void printTreeVerticallyRecur(struct treeNode* root, int horizDist, struct hMap* m)
{
    hashInsert1(root->data, m, horizDist);

    printTreeVerticallyRecur(root->left, horizDist-1, m);
    printTreeVerticallyRecur(root->right, horizDist+1, m);
}

void hashInsert1(int key, struct hMap* m, int horizDist)
{
    //write/use a good hash function
    //store horizDist as the hash input to distinguish between collided keys
}

struct hMap* newHashMap(int N)
{
    struct hMap* m = (struct hMap*)malloc(sizeof(struct hMap));     //allocate memory for map info
    m->N = N;   //size of table
    m->table = (struct hMapEntry*)malloc(N*sizeof(struct hMapEntry));  //allocate memory for table

    int i;
    for(i=0; i<N; i++)          //initialize all next pointers to null
    {
        m->table[i].next = 0;
    }

    return m;
}
