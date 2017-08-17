#include "main.h"
#include <stdlib.h>
#include <math.h>

struct primeNode
{
    int key;
    struct primeNode* next;
    struct primeNode* prev;
};

//auxiliary functions
struct primeNode* getPrimesUpTo(int X);
int isPrime(int X, struct primeNode* primeList);
void hSort(int* A, int len, int h);

void shellSort(int* A, int len)
{
    //generate list of primes
    struct primeNode* primeList = getPrimesUpTo(len/3);

    //initialize p to be the largest prime <= len/3
    struct primeNode* p = primeList->prev;

    //primeList will always have at least one node (with key = 1)
    while(p->key > 1)
    {
        hSort(A, len, p->key);
        p = p->prev;
    }

    //finally, 1-sort
    insertionSort(A, len);
}

//assumes h <= len
void hSort(int* A, int len, int h)
{
    //get number of elements in an h-subarray of A
    int maxElems = len/h;
    if(len%h)
        maxElems = maxElems + 1;

    //create array to be sorted
    int* B = (int*)malloc(maxElems*sizeof(int));

    int i;
    for(i=0; i<h; i++)
    {
        //get length of subarray to be sorted
        int subLen = maxElems;
        if((maxElems-1)*h + i >= len)   //if we would have indexed past the end of the array
        {
            subLen = subLen - 1;            //shorten the working array length
        }

        //populate array
        int j;
        for(j=0; j<subLen; j++)
        {
            B[j] = A[j*h + i];
        }

        //sort h-subarray
        insertionSort(B, subLen);

        //put back in original array
        for(j=0; j<subLen; j++)
        {
            A[j*h + i] = B[j];
        }
    }
}

//returns a linked list of primes <= X
struct primeNode* getPrimesUpTo(int X)
{
    //prepend 1 to the list of primes
    struct primeNode* one = (struct primeNode*)malloc(sizeof(struct primeNode));
    one->key = 1;
    one->next = 0;
    one->prev = 0;

    //keep track of largest prime so far
    struct primeNode* lastPrime = one;

    //check all numbers up to the square root of X
    int i;
    for(i=2; i<=X; i++)
    {
        if(isPrime(i, one->next))
        {
            struct primeNode* thisPrime = (struct primeNode*)malloc(sizeof(struct primeNode));
            thisPrime->key = i;
            thisPrime->next = 0;
            thisPrime->prev = lastPrime;
            lastPrime->next = thisPrime;
            lastPrime = thisPrime;
        }
    }

    //make the list circular
    one->prev = lastPrime;

    return one;
}

//returns 1 if X is not a multiple of any key of a node in primeList
int isPrime(int X, struct primeNode* primeList)
{
    struct primeNode* node = primeList;

    while(node && node->key < X)    //while there is another prime less than X
    {
        if(X%(node->key) == 0)          //check if it is a factor of X
            return 0;

        node = node->next;
    }

    //if no prime was a factor, X is prime
    return 1;
}
