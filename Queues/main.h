struct queueNode
{
    int data;
    struct queueNode* next;
    struct queueNode* prev;
};

struct arrQ
{
    int N;
    int* arr;
    int iFront;
    int iBack;
    int isEmpty;
};

struct stackNode
{
    int data;
    struct stackNode* next;
};

struct stackQ
{
    struct stackNode* first;
    struct stackNode* rest;
};

struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct kQueue
{
    int k;
    struct queueNode* empties;
};

struct tupleQNode
{
    int i;
    int j;
    struct tupleQNode* next;
    struct tupleQNode* prev;
};

struct tuple
{
    int i;
    int j;
};

struct listNode
{
    int data;
    struct listNode* next;
};

void enqueue(struct queueNode** back, int data);
int dequeue(struct queueNode** back);
int frontVal(struct queueNode* back);
int backVal(struct queueNode* back);
int isEmpty(struct queueNode* back);
void printQueue(struct queueNode* back);

void enqueue2(struct tupleQNode** back, int i, int j);
struct tuple* dequeue2(struct tupleQNode** back);
struct tuple* frontVal2(struct tupleQNode* back);
struct tuple* backVal2(struct tupleQNode* back);
int isEmpty2(struct tupleQNode* back);
void printQueue2(struct tupleQNode* back);

struct arrQ* createArrQ(int N);
int isFull(struct arrQ* q);
int arrEnqueue(struct arrQ* q, int data);
int arrDequeue(struct arrQ* q);
int arrQFront(struct arrQ* q);
int arrQBack(struct arrQ* q);
void moveBack(struct arrQ* q);
void moveFront(struct arrQ* q);
void printArrQ(struct arrQ* q);
void destroyArrQ(struct arrQ* q);

void insertFront(struct queueNode** back, int data);
void insertBack(struct queueNode** back, int data);
void deleteFront(struct queueNode** back);
void deleteBack(struct queueNode** back);
int getFront(struct queueNode* back);
int getBack(struct queueNode* back);
int isEmptyDeque(struct queueNode* back);
void printDeque(struct queueNode* back);

struct arrQ* createArrDeque(int N);
void insertFrontArr(struct arrQ* q, int data);
void insertBackArr(struct arrQ* q, int data);
void deleteFrontArr(struct arrQ* q);
void deleteBackArr(struct arrQ* arrDeque);
int getFrontArr(struct arrQ* q);
int getBackArr(struct arrQ* q);
void moveBackFwd(struct arrQ* q);
void moveFrontFwd(struct arrQ* q);
void printArrDeque(struct arrQ* q);
void destroyArrDeque(struct arrQ* q);

int stackIsEmpty(struct stackNode* top);
int peek(struct stackNode* top);
int pop(struct stackNode** oldTop);
void printStack(struct stackNode* top);
void push(struct stackNode** oldTop, int data);

struct stackQ* createStackQ();
int sqIsEmpty(struct stackQ* sq);
void sqEnqueue(struct stackQ* sq, int data);
int sqDequeue(struct stackQ* sq);
int sqFrontVal(struct stackQ* sq);
int sqBackVal(struct stackQ* sq);
void printSQ(struct stackQ* sq);

struct kQueue* createKQ(int k);
struct queueNode* addQueue(struct kQueue* kQ, int data);
void enKQueue(struct kQueue* kQ, struct queueNode** back, int data);
int deKQueue(struct kQueue* kQ, struct queueNode** back);
