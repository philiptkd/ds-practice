#include <stdio.h>
#include "main.h"

//for each element in the array, prints the nearest greater element to the right of it
//if there is no greater element to the right, prints -1
//completes in O(n) time and O(n) space
//does not preserve order when printing
//assumes the array has at least one element

void nextLarger(int* arr, int N)
{
    struct stackNode* top = 0;
    int i = 0;
    push(&top, *(arr + i));

    for(i=1; i<N; i++)
    {
        int current = *(arr + i);
        int last = peek(top);
        while(current > last)         //goes back down the stack to see what else is smaller and without a next larger value assigned yet
        {
            printf("%d --> %d\n", last, current);
            pop(&top);                          //if a next larger value was assigned, take it off the stack
            if(!isEmpty(top))
                { last = peek(top); }
            else
                { break; }                      //stop if the stack is empty

        }
        push(&top, current);                    //put current element on stack, ensuring stack is never empty
    }
    while(!isEmpty(top))                        //everything still on the stack had no next larger element
    {
        printf("%d --> %d\n", pop(&top), -1);
    }
}
