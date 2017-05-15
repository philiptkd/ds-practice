#include "main.h"

struct node* createList();
void printList(struct node* n);
void push(struct node** oldHead, int newHeadVal);
void insertAfter(struct node* refNode, int insertVal);
void append(struct node* head, int toAppendVal);

void insertNodeDemo()
{
    struct node* list = createList();
    insertAfter(list, 64);
    push(&list, 20);
    append(list, 9);
    printList(list);
}
