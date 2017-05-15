#include "main.h"

int operate(int leftOp, int rightOp, char c);

//evaluates a postfix expression
//assumes all operands are single digit whole numbers and all operators are one of +,-,*,/, and ^
//could be extended to handle multiple digit whole numbers with the use of spaces
//uses integer division
//assumes the input is a valid postfix expression
int evalPostFix(char* expr)
{
    struct stackNode* top = 0;              //beginnings of a stack for the operators

    int i = 0;              //index of character in expression
    char c = *(expr + i);   //character in expression
    while(c)
    {
        if(c >= '0' && c <= '9')
        {
            push(&top, (int)(c - '0'));     //put operands on the stack
        }
        else        //we assume c is an operator
        {
            int rightOp = pop(&top);                    //get the last two operands
            int leftOp = pop(&top);
            push(&top, operate(leftOp, rightOp, c));    //perform operation and push answer back onto stack
        }
        i++;
        c = *(expr + i);
    }
    return pop(&top);
}

int operate(int leftOp, int rightOp, char c)
{
    int ret;
    switch(c)
    {
        case '+':
            return leftOp + rightOp;
        case '-':
            return leftOp - rightOp;
        case '*':
            return leftOp * rightOp;
        case '/':
            return leftOp / rightOp;
        case '^':
            ret = 1;
            while(rightOp)
            {
                ret = ret * leftOp;
                rightOp--;
            }
            return ret;
    }
    return 0;       //something to catch invalid characters
}
