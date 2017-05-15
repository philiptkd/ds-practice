#include "main.h"

void insertAtBottom(struct stackNode** top, int data);

//recursively reverses a stack using no extra memory on the heap
//instead, stores everything on the function call stack
//uses O(n^2) time and O(n) extra space on the function call stack
//obviously could be done in O(n) time if we pushed all elements to a new stack, but the constraint to not use the heap was interesting
void reverseStack(struct stackNode** top)
{
    int topVal = pop(top);  //get a value off the stack
    if(isEmpty(*top))    //if that was the last node
    {
        push(top, topVal);  //put it back
    }
    else    //if there are more, keep going
    {
        reverseStack(top);
        insertAtBottom(top, topVal);        //first called when the stack has only one element.
        //now all remaining instances of this function insert at the bottom the value they popped off
    }
}

//puts data at the bottom of the given stack
void insertAtBottom(struct stackNode** top, int data)
{
    int topVal = pop(top);      //take off the top value
    if(isEmpty(*top))           //if that was the last value
    {
        push(top, data);        //push data onto the bottom of the stack
    }
    else
    {
        insertAtBottom(top, data);  //else keep taking off
    }
    push(top, topVal);      //first reached after pushing data to the bottom. now all instances of this function push back what they popped off
}
