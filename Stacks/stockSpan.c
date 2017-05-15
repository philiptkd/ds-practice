#include "main.h"
#include <stdlib.h>

//for each element in an array, finds the number of consecutive elements to its left that are less than or equal to it, counting itself
//for example, input {100, 80, 60, 70, 60, 75, 85} gives output  {1, 1, 1, 2, 1, 4, 6}
//assumes N >= 1
//runs in O(n) time and uses O(n) extra space
int* stockSpan(int* arr, int N)
{
    int* spans = (int*)malloc(N*sizeof(int));   //array to store answers
    struct stackNode* dataTop = 0;      //to store data
    struct stackNode* indexTop = 0;     //to store indexes of data in stack. could just create larger stack nodes, but I don't want to

    push(&dataTop, arr[N-1]);  //push the first (last) element onto the stack
    push(&indexTop, N-1);

    int i;
    for(i=N-2; i>=0; i--)
    {
        while(!isEmpty(dataTop) && arr[i] > peek(dataTop))      //if this element is larger than the one at the top of the stack
        {
            pop(&dataTop);                               //pop the other one off the stack. we've found the end of its span
            int poppedIndex = pop(&indexTop);            //get the original array index of the element on the stack
            spans[poppedIndex] = poppedIndex - i;       //the length of the span is the difference of the indexes
        }
        push(&dataTop, arr[i]);                  //when nothing on the stack is larger than this value, push it on
        push(&indexTop, i);                      //push the corresponding index
    }

    //here, i=-1
    while(!isEmpty(dataTop))                //all the remaining elements on the stack are larger than all elements to their left
    {
        pop(&dataTop);                               //pop everything off both stacks
        int poppedIndex = pop(&indexTop);
        spans[poppedIndex] = poppedIndex - i;
    }

    return spans;
}
