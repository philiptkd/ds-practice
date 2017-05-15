#include <stdio.h>
#include <stdlib.h>
#include "main.h"

struct listNode* createExList(int N);
struct treeNode* list2Tree(struct listNode* head);
void printTree(struct treeNode* root);

int main()
{
    int N = 10;
    struct listNode* head = createExList(N);
    struct treeNode* tree = list2Tree(head);
    printTree(tree);

    return 0;
}
