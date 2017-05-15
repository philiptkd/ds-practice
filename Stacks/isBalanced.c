#include "main.h"

//checks if a string of parentheses is balanced and valid
//assumes the only characters in the string are (,),[,],{, and }.
//assumes no spaces
//an input something like "[(){}]" returns true, but something like "[(])" or "[[]" returns false
int isBalanced(char* str)
{
    struct stackNode* top = 0;
    int i = 0;
    char c = *(str + i);
    while(c)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            push(&top, (int)c);
        }
        else    //we assume it is a closing bracket of some kind
        {
            if(isEmpty(top))        //if there is no open bracket for this close bracket, it's not balanced
                return 0;

            char prev = (char)pop(&top);
            switch(c)
            {
                case ')':
                    if(prev != '(')
                        return 0;
                    break;
                case ']':
                    if(prev != '[')
                        return 0;
                    break;
                case '}':
                    if(prev != '{')
                        return 0;
                    break;
                default:
                    return 0;
            }
        }
        i++;
        c = *(str + i);
    }
    if(!isEmpty(top))       //if the stack is not empty, then there were more open brackets than close brackets
        return 0;

    return 1;
}
