#include "main.h"
#include <stdio.h>

struct node* createBiggerList();
void printList(struct node* n);
int getNth(struct node* head, int N);
int getMid(struct node* head);
int nthFromEnd(struct node* head, int N);
void deleteList(struct node* head);
int numTimes(struct node* head, int X);
void reverse(struct node** head);
struct node* createCircularList();

int main()
{
    struct node* head = createCircularList();
    return 0;
}
