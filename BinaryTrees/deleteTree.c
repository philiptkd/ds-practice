#include "main.h"
#include <stdlib.h>

void deleteTree(struct treeNode** root)
{
    if(!(*root))       //an empty tree doesn't need deleting
        return;

    deleteTree(& ((*root)->left) );     //delete left side
    deleteTree(& ((*root)->right) );    //delete right side

    //delete root
    free(*root);

    //rename root to be NULL
    *root = 0;
}
