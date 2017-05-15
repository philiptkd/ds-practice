//just like nextLarger(), but returns an array of indices
//uses two stacks to avoid having to create a new struct in order to push more info to the stack each time
//the 2nd stack stores corresponding indices of the elements in the 1st stack
//assumes the array has at least one element

#include "main.h"
#include <stdlib.h>

int* nextSmaller(int* arr, int N)
{
    struct stackNode* top = 0;          //top of data stack
    struct stackNode* iTop = 0;         //top of index stack

    int* ans = (int*)malloc(N*sizeof(int));     //array to hold indices of next smaller elements

    int i = 0;
    push(&top, *(arr + i));
    push(&iTop, i);

    for(i=1; i<N; i++)
    {
        int current = *(arr + i);
        int last = peek(top);
        while(current < last)         //goes back down the stack to see what else is larger and without a next smaller value assigned yet
        {
            ans[pop(&iTop)] = i;              //in the new array, at the index of the item just popped, store the index of the next smaller value
            pop(&top);                          //if a next smaller value was assigned, take it off the stack
            if(!isEmpty(top))
                { last = peek(top); }           //keep comparing stack values to current value
            else
                { break; }                      //stop if the stack is empty

        }
        push(&top, current);                    //put current element on stack, ensuring stack is never empty
        push(&iTop, i);                             //push corresponding index
    }
    while(!isEmpty(iTop))                        //everything still on the stack had no next larger element
    {
        ans[pop(&iTop)] = N;
    }

    return ans;
}
