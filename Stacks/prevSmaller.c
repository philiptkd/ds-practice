//just like nextSmaller(), but returns an array of indices of next smaller element to the LEFT

#include "main.h"
#include <stdlib.h>

int* prevSmaller(int* arr, int N)
{
    struct stackNode* top = 0;          //top of data stack
    struct stackNode* iTop = 0;         //top of index stack

    int* ans = (int*)malloc(N*sizeof(int));     //array to hold indices of prev smaller elements

    int i = N-1;
    push(&top, *(arr + i));
    push(&iTop, i);

    for(i=N-2; i>=0; i--)
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
        ans[pop(&iTop)] = -1;
    }

    return ans;
}
