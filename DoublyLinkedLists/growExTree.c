#include "main.h"
#include <stdlib.h>

//manually constructs an example tree
struct leaf* growExTree()
{
    //allocate memory and assign values
    struct leaf* top = (struct leaf*)malloc(sizeof(struct leaf));
    (*top).val = 10;

    struct leaf* topL = (struct leaf*)malloc(sizeof(struct leaf));
    (*topL).val = 12;

    struct leaf* topLL = (struct leaf*)malloc(sizeof(struct leaf));
    (*topLL).val = 25;

    struct leaf* topLR = (struct leaf*)malloc(sizeof(struct leaf));
    (*topLR).val = 30;

    struct leaf* topR = (struct leaf*)malloc(sizeof(struct leaf));
    (*topR).val = 15;

    struct leaf* topRL = (struct leaf*)malloc(sizeof(struct leaf));
    (*topRL).val = 36;

    //set pointers
    (*top).left = topL;
    (*top).right = topR;
    (*topL).left = topLL;
    (*topL).right = topLR;
    (*topR).left = topRL;
    (*topR).right = 0;
    (*topLL).left = 0;
    (*topLL).right = 0;
    (*topLR).left = 0;
    (*topLR).right = 0;
    (*topRL).left = 0;
    (*topRL).right = 0;

    return top;
}
