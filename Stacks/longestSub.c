#include "main.h"

//given a string of parentheses, e.g. "((()()(", give the length of the longest balanced substring
int longestSub(char* str)
{
    struct stackNode* top = 0;      //name for a stack to use
    int i = 0;
    char c = *(str + i);
    int longest = 0;            //to keep track of length of longest balanced substring

    push(&top, -1);                 //to serve as a reference for lengths of balanced substrings that use i = 0
                                        //for example, "()"
                                            //in the algorithm below, reaching ')' causes '(' to be popped
                                            //then the length of the substring is calculated as i( ')' ) - i(pop(&top))
                                                //a value of -1 ensures our output, in this case, is 1-(-1) = 2

    while(c)
    {
        if(c == '(')                //push '(' to the stack, to be popped when ')' are encountered
        {
            push(&top, i);
        }
        else        //we assume ')'
        {
            pop(&top);              //pop the last '('. if it was ')', the stack is now empty
            if(!isEmpty(top))   //if it was a '(', it formed a balanced substring from it to i
            {
                int startIndex = peek(top);     //use the index of the element to its left to calculate length
                if(i - startIndex > longest)
                {
                    longest = i - startIndex;
                }
            }
            else        //the stack is now empty
            {
                push(&top, i);  //push the index of this ')' to be a new start index.
                                    //this is the only time a ')' is pushed
            }
        }
        i++;
        c = *(str + i);
    }
    return longest;
}
