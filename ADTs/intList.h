#include "main.h"

#ifndef INTLIST
#define INTLIST

typedef struct intListType *intListPtr;

//constructs new list by appending to the front
intListPtr cons(int X, intListPtr oldList);

//get first
int first(intListPtr aList);

//get pointer to list after first element
intListPtr rest(intListPtr aList);

//print list
void printIntList(intListPtr aList);

#endif // INTLIST
