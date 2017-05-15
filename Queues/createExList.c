#include "main.h"
#include <stdlib.h>

//assumes N>=1
struct listNode* createExList(int N)
{
    struct listNode* head = (struct listNode*)malloc(N*sizeof(struct listNode));

    //initialize most nodes
    int i;
    for(i=0; i<N-1; i++)
    {
        (*(head + i)).data = i;
        (*(head + i)).next = (head + i+1);
    }

    //initialize last nodes
    (*(head + i)).data = i;
    (*(head + i)).next = 0;

    return head;
}
