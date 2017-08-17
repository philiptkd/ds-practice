#ifndef STACK
#define STACK

typedef struct StackStructType *StackPtr;

//create empty stack
StackPtr createStack();

//destroy stack
void destroyStack(StackPtr sPtr);

//push onto stack
void push(int X, StackPtr sPtr);

//pop off of stack. returns value popped off.
int pop(StackPtr sPtr);

//peek
int peek(StackPtr sPtr);

//print
void printStack(StackPtr sPtr);

#endif // STACK
