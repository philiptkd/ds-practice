#include "main.h"

//given a matrix of 0s (empty spaces), 1s (fresh oranges), and 2s (rotten oranges)
//finds the minimum time required for all oranges to rot
//a rotten orange causes adjacent fresh oranges to rot in one time unit
//runs in O(M+N) time
int rotTime(int* arr, int N, int M)
{
    struct tupleQNode* tupleQ = 0;      //queue to hold 2s
    int time = 0;       //to keep track of depth of search, i.e. time elapsed

    //loop over matrix to find all 2s and enqueue them
    int i,j;
    for(i=0; i<N; i++)      //for each row
    {
        for(j=0; j<M; j++)      //for each column in that row
        {
            if(*(arr + i*M + j) == 2)      //if there is a rotten orange
            {
                enqueue2(&tupleQ, i, j);    //enqueue the coordinates
            }
        }
    }

    //enqueue a delimiter
    enqueue2(&tupleQ, -1, -1);

    while(!isEmpty2(tupleQ)) //for each 2 on the queue,
    {
        struct tuple* tup = dequeue2(&tupleQ);   //dequeue it
        int y = tup->i;
        int x = tup->j;

        //if we reached a delimiter
        if(x == -1 && y == -1)
        {
            //if there are more 2s to be processed
            if(!isEmpty2(tupleQ))
                { enqueue2(&tupleQ, -1, -1); } //enqueue another delimiter b/c we have just finished enqueueing another level of 2s

            time++;         //increment the time passed
            continue;       //skip the rest of the while loop
        }

        //for each 1 adjacent to it, change to a 2 and enqueue it
        if(y > 0 && *(arr + (y-1)*M + x) == 1)
        {
            *(arr + (y-1)*M + x) = 2;
            enqueue2(&tupleQ, y-1, x);
        }
        if(y < N-1 && *(arr + (y+1)*M + x) == 1)
        {
            *(arr + (y+1)*M + x) = 2;
            enqueue2(&tupleQ, y+1, x);
        }
        if(x > 0 && *(arr + y*M + x-1) == 1)
        {
            *(arr + y*M + x-1) = 2;
            enqueue2(&tupleQ, y, x-1);
        }
        if(x < M-1 && *(arr + y*M + x+1) == 1)
        {
            *(arr + y*M + x+1) = 2;
            enqueue2(&tupleQ, y, x+1);
        }
    }

    //loop over matrix to find any 1s left over
    for(i=0; i<N; i++)      //for each row
    {
        for(j=0; j<M; j++)      //for each column in that row
        {
            if(*(arr + i*M + j) == 1)      //if there is a rotten orange
            {
                printf("Not all oranges will rot.\n");
                return -1;
            }
        }
    }

    return --time;
}
