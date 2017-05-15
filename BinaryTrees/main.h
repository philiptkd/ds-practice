struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct queueNode
{
    int data;
    struct queueNode* next;
    struct queueNode* prev;
};

struct stackNode
{
    int data;
    struct stackNode* next;
};

struct treeNode* newNode(int data);
void printTreeInOrder(struct treeNode* root);
void printTreePreOrder(struct treeNode* root);
void printTreePostOrder(struct treeNode* root);
void printTreeLevelOrder(struct treeNode* root);

void enqueue(struct queueNode** back, int data);
int dequeue(struct queueNode** back);
int frontVal(struct queueNode* back);
int backVal(struct queueNode* back);
int isEmpty(struct queueNode* back);
void printQueue(struct queueNode* back);

int stackIsEmpty(struct stackNode* top);
int peek(struct stackNode* top);
int pop(struct stackNode** oldTop);
void printStack(struct stackNode* top);
void push(struct stackNode** oldTop, int data);

void insertFront(struct queueNode** back, int data);
void insertBack(struct queueNode** back, int data);
void deleteFront(struct queueNode** back);
void deleteBack(struct queueNode** back);
int getFront(struct queueNode* back);
int getBack(struct queueNode* back);
int isEmptyDeque(struct queueNode* back);
void printDeque(struct queueNode* back);
