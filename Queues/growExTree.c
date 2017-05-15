#include "main.h"
#include <stdlib.h>

//uses the same method as rotTime()
//runs in O(n) time, where n is the number of nodes in the tree
struct treeNode* growExTree()
{
    //allocate memory for and initialize all nodes
    int N = 7;
    struct treeNode* arr = (struct treeNode*)malloc(N*sizeof(struct treeNode));
    int i;
    for(i=0; i<N; i++)
    {
        arr[i].data = i;
        arr[i].left = 0;
        arr[i].right = 0;
    }

    //set pointers for nodes to use
    arr[0].left = &arr[1];


    //return the root
    return &arr[0];
}
