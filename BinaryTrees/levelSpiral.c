#include "main.h"
#include <stdio.h>

//uses a deque to print a tree in level order, alternating directions of levels
//using a queue structure meant to store ints because I'm lazy and it works on my machine

void levelSpiral(struct treeNode* root)
{
    struct queueNode* q = 0;    //double-ended queue to hold tree nodes

    insertBack(&q, -1);         //put a delimiter on the queue to signal the end of a level
    insertBack(&q, (int)root);  //put root on queue and print it
    printf("%d ", root->data);

    int dir = 1;                //a direction of 0 will indicate left-to-right, 1 right-to-left

    while(!isEmptyDeque(q))
    {
        struct queueNode* node;
        if(dir == 0)            //the "normal" direction
        {
            node = (struct queueNode*)getFront(q);
            deleteFront(&q);    //"dequeue" it

            if((int)node == -1) //if it was a delimiter, we've reached the end of a level
            {
                if(isEmptyDeque(q))     //if there are no more nodes to print, stop
                    return;

                insertFront(&q, -1);    //if there were more nodes, put the delimiter back
                dir = 1;    //switch directions
                continue;
            }
            else    //it wasn't a delimiter
            {
                if(node->prev)  //enqueue and print the left
                {
                    insertBack(&q, (int)node->prev);
                    printf("%d ", node->prev->data);
                }
                if(node->next) //then the right
                {
                    insertBack(&q, (int)node->next);
                    printf("%d ", node->next->data);
                }
            }
        }

        else    //if dir == 1,      the "backwards" direction
        {
            node = (struct queueNode*)getBack(q);
            deleteBack(&q);     //"dequeue" it

            if((int)node == -1) //if it was a delimiter, we've reached the end of a level
            {
                if(isEmptyDeque(q))     //if there are no more nodes to print, stop
                    return;

                insertBack(&q, -1);     //if there were more nodes, put the delimiter back
                dir = 0;    //switch directions
                continue;
            }
            else    //it wasn't a delimiter
            {
                if(node->next)     //enqueue and print the right
                {
                    insertFront(&q, (int)node->next);
                    printf("%d ", node->next->data);
                }
                if(node->prev)      //then the left
                {
                    insertFront(&q, (int)node->prev);
                    printf("%d ", node->prev->data);
                }
            }
        }
    }
}
