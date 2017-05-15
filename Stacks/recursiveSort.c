#include "main.h"

void insertIntoSorted(struct stackNode** top, int data);

//sorts a stack using recursion
//no looping constructs or extra memory on the heap are used
//this is similar to reverseStack() in that all extra memory used is on the function call stack
//worst case would be to reverse the stack, which takes O(n^2) time
//uses O(n) extra space on the function call stack
void recursiveSort(struct stackNode** top)
{
    int topVal = pop(top);      //get a value off the stack
    if(isEmpty(*top))    //if that was the last node
    {
        push(top, topVal);  //put it back
    }
    else    //if there are more, keep going
    {
        recursiveSort(top);
        insertIntoSorted(top, topVal);        //first called when the stack has only one element, which is considered to be sorted
        //now all instances of this function insert values into sorted stacks so that they remain sorted
    }
}

void insertIntoSorted(struct stackNode** top, int data)
{
    if(isEmpty(*top))       //if it's empty, then data was greater than all values that were on the stack.
    {
        push(top, data);    //put it at the bottom
        return;
    }

    //here, we know the stack is not empty
    int topVal = peek(*top);
    if(topVal > data)           //if data is less than all values on the stack
    {
        push(top, data);        //put it at the top
    }
    else                    //if data is greater than the top value, insert it further down the stack
    {
        pop(top);                       //take off the top element so the next can be accessed
        insertIntoSorted(top, data);    //the value is sorted into the stack
        push(top, topVal);              //put back topVal, which was less than data
    }
}
