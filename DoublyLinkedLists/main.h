struct doubleNode
{
    int val;
    struct doubleNode* next;
    struct doubleNode* prev;
};

struct leaf
{
    int val;
    struct leaf* left;
    struct leaf* right;
};
