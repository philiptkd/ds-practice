#include "main.h"

int plainPri(char c);
int pri(int priAndChar);
int val(int priAndChar);

//converts an expression from infix to postfix
//assumes a well-formed input, with only lower case letters as operands and the operations +,-,*,/, and ^, as well as ( and )
    //well-formed also implies a valid infix expression with no spaces
//assigns to each char in the stack a priority, which is stuffed above the lowest 8 bits of the integer data field of the stack node
//alters original expression
void inFix2PostFix(char* expr)
{
    struct stackNode* top = 0;              //beginnings of a stack for the operators

    int i = 0;              //index of character in expression
    int owr = 0;            //overwrite index of expression
    int addToPriority = 0;       //number to add to each operator's priority
    char c = *(expr + i);   //character in expression
    while(c)
    {
        if(c == '(')
        {
            addToPriority = addToPriority + 10;
        }
        else if(c == ')')
        {
            addToPriority = addToPriority - 10;
        }
        else if(c < 97)  //all lowercase letters have ascii codes at least 97. all operators we're considering have codes < 97
        {
            while(!isEmpty(top) && pri(peek(top)) >= plainPri(c) + addToPriority)    //if the stack isn't empty and top's operation has a priority at least as great as
            {
                *(expr + owr) = (char)val(pop(&top));              //pop the last char off the stack and write it to its new loc in the expression
                owr++;
            }
            push(&top, ((plainPri(c) + addToPriority)<<8) + c);   //the lower 8 bits is the char, everything else is its priority
        }
        else            //we assume it is an operand
        {
            *(expr + owr) = c;          //write operand to its new location
            owr++;
        }
        i++;
        c = *(expr + i);        //go to next char in the expression
    }
    //here, we've reached the end of the expression
    //pop off the rest of the operators
    while(!isEmpty(top))
    {
        *(expr + owr) = (char)val(pop(&top));  //write operators to new locations
        owr++;
    }

    //because of '(' and ')', the output expression might be shorter than the input expression
    //write 0x0 to end the C string
    *(expr + owr) = 0;
}

//gives a priority to different operations
int plainPri(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;       //catches invalid characters < 97. these will print at the end of the output expression
}

//un-stuffs the priority from above the character value in an int field
int pri(int priAndChar)
{
    return priAndChar>>8;       //shift right by 8 bits to get rid of the char value
}

//extracts just the value of the character from the priority-character integer field
int val(int priAndChar)
{
    return (int)((char)priAndChar);         //casts to char to chop off everything but bottom 8 bits, then casts back to return
}
