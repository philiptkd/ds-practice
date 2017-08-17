#include "main.h"
#include "stack.h"
#include "intList.h"

intListPtr deleteFromIntList(intListPtr aList, int X);

int main()
{
    intListPtr aList = 0;
    aList = cons(8, aList);
    aList = cons(7, aList);
    aList = cons(6, aList);
    aList = cons(5, aList);
    aList = cons(4, aList);
    aList = cons(3, aList);
    aList = cons(2, aList);
    aList = cons(1, aList);

    printIntList(aList);

    intListPtr bList = deleteFromIntList(aList, 5);

    printIntList(bList);
    return 0;
}

//deletes the first occurrence of X from the list using only the ADT fns defined in intList.h
intListPtr deleteFromIntList(intListPtr aList, int X)
{
    if(aList == 0)
        return 0;

    if(first(aList) == X)
        return rest(aList);

    return cons(first(aList), deleteFromIntList(rest(aList), X));
}
