struct minHeap
{
    int arrSize;
    int heapSize;
    int* heapArr;
};

struct binomialTreeNode
{
    int data;
    struct binomialTreeNode* leftChild;
    struct binomialTreeNode* rightSibling;
};

struct fibTreeNode
{
    int data;
    struct fibTreeNode* leftChild;
    struct fibTreeNode* leftSibling;
    struct fibTreeNode* rightSibling;
};

struct fibHeap
{
    struct fibTreeNode* leftRoot;
    struct fibTreeNode* minNode;
    int maxHeight;
};
