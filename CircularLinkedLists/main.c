#include "main.h"

struct node* createList();
void printList(struct node* head);
void split(struct node* head, struct node** ret);
void sortedInsert(struct node** head, int X);

int main()
{
    struct node* head = createList();
    sortedInsert(&head, 10);
    printList(head);

    return 0;
}
