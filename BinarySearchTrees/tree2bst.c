#include "main.h"
#include <stdlib.h>

//takes a tree and converts it to a BST with the same structure
//does this in O(n*logn) time and O(n) extra space
void tree2bst(struct treeNode* root)
{
    //get size. takes O(n) time and uses O(h) extra space
    int N = getSize(root);

    //create array. O(n) extra space
    int* arr = (int*)malloc(N*sizeof(int));

    //fill array from in order traversal of tree.  O(n) time and O(h) extra space
    fillArray(root, arr);

    //sort array. O(n*logn) time and O(n) extra space
    mergeSort(arr, N);

    //fill tree in order with sorted contents of array. O(n) time and O(h) extra space
    fillTree(root, arr);
}
