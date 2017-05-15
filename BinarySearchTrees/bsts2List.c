#include "main.h"

//takes 2 BSTs and returns a sorted list of their nodes
struct listNode* bsts2List(struct treeNode* root1, struct treeNode* root2)
{
    //memory for tree1
    struct stackNode* treeStack1 = 0;
    struct treeNode* alreadyVisited1 = (struct treeNode*)(-1);
    struct treeNode* next1 = 0;

    //memory for tree2
    struct stackNode* treeStack2 = 0;
    struct treeNode* alreadyVisited2 = (struct treeNode*)(-1);
    struct treeNode* next2 = 0;

    //doubly-linked list to create
    struct listNode* head = 0;
    struct listNode* tail = 0;

    //flags for moving forward or back across the tree.
    int getNext1Flag;
    int getNext2Flag;

    //get first and last nodes
    next1 = getNextInOrder(&root1, &alreadyVisited1, &treeStack1);
    next2 = getNextInOrder(&root2, &alreadyVisited2, &treeStack2);

    //fill list
    while(next1 || next2)
    {
        if(next1 && next2)
        {
            if(next1->data < next2->data)   //if next1 is the next smallest node
            {
                if(head)    //if the list is not empty
                {
                    struct listNode* newTail = newListNode(next1->data);    //add next1 to the list
                    tail->next = newTail;
                    newTail->prev = tail;
                    tail = newTail;
                }
                else    //if the list is empty
                {
                    head = newListNode(next1->data);
                    tail = head;
                }

                getNext1Flag = 1;
                getNext2Flag = 0;
            }
            else    //if(next1->data > next2->data)
            {
                if(head)    //if the list is not empty
                {
                    struct listNode* newTail = newListNode(next2->data);    //add next2 to the list
                    tail->next = newTail;
                    newTail->prev = tail;
                    tail = newTail;
                }
                else    //if the list is empty
                {
                    head = newListNode(next2->data);
                    tail = head;
                }

                getNext1Flag = 0;
                getNext2Flag = 1;
            }
        }
        else if(!next2)     //we know the list is not empty, because we know neither of the trees were empty
        {
            struct listNode* newTail = newListNode(next1->data);    //add next1 to the list
            tail->next = newTail;
            newTail->prev = tail;
            tail = newTail;

            getNext1Flag = 1;
            getNext2Flag = 0;
        }
        else if(!next1)
        {
            struct listNode* newTail = newListNode(next2->data);    //add next2 to the list
            tail->next = newTail;
            newTail->prev = tail;
            tail = newTail;

            getNext1Flag = 0;
            getNext2Flag = 1;
        }


        if(getNext1Flag)
            next1 = getNextInOrder(&root1, &alreadyVisited1, &treeStack1);
        if(getNext2Flag)
            next2 = getNextInOrder(&root2, &alreadyVisited2, &treeStack2);
    }

    return head;
}
