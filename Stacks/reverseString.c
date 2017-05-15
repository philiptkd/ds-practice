#include "main.h"

void reverseString(char* str)
{
    struct stackNode* top = 0;
    int i = 0;
    char c = *(str + i);

    //push each character onto stack
    while(c)
    {
        push(&top, (int)c);
        i++;
        c = *(str + i);
    }

    //pop each character off of stack
    int j;
    for(j=0; j<i; j++)
    {
        *(str + j) = (char)pop(&top);
    }

    //the NULL from the original cstring will still be there
}
