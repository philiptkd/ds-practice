#include "main.h"
#include <stdlib.h>

//creates an example list to use with copyWithRand()
struct doubleNode* createExRandList()
{
    struct doubleNode* first = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    struct doubleNode* second = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    struct doubleNode* third = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    struct doubleNode* fourth = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    struct doubleNode* fifth = (struct doubleNode*)malloc(sizeof(struct doubleNode));

    (*first).val = 1;
    (*first).next = second;
    (*second).val = 2;
    (*second).next = third;
    (*third).val = 3;
    (*third).next = fourth;
    (*fourth).val = 4;
    (*fourth).next = fifth;
    (*fifth).val = 5;
    (*fifth).next = 0;

    (*first).prev = third;
    (*second).prev = first;
    (*third).prev = fifth;
    (*fourth).prev = third;
    (*fifth).prev = second;

    return first;
}
