#include "main.h"
#include <stdio.h>

//prints binary from 1 to N using a queue
//using strings/characters would take up less space,
    //but I already have a queue struct for int's soo...
void genBinary(int N)
{
    struct queueNode* q = 0;
    enqueue(&q, 1);

    int i;
    for(i=0; i<N; i++)
    {
        int tmp = dequeue(&q);
        printf("%d ", tmp);
        enqueue(&q, tmp*10);
        enqueue(&q, tmp*10 + 1);
    }

}
