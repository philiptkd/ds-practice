struct stackNode
{
    int data;
    struct stackNode* next;
};

typedef struct dblStack
{
    int lastLeftIndex;
    int lastRightIndex;
    int lenDataSection;
    int* stackArray;
} DblStack;

struct getMinStack
{
    struct stackNode* dataStack;
    struct stackNode* minStack;
};

struct queueNode
{
    int data;
    struct queueNode* next;
    struct queueNode* prev;
};

struct queueStack
{
    struct queueNode* popQueue;
    struct queueNode* mainQueue;
};

struct midStackNode
{
    int data;
    struct midStackNode* up;
    struct midStackNode* down;
};

struct midStack
{
    int parity;
    struct midStackNode* top;
    struct midStackNode* mid;
};

struct kStacks
{
    int N;
    struct stackNode* nextEmpty;
};

struct stackNode* createStack(int N);
int isEmpty(struct stackNode* top);
int peek(struct stackNode* top);
int pop(struct stackNode** oldTop);
void printStack(struct stackNode* top);
void push(struct stackNode** oldTop, int data);

DblStack* arrayDoubleStack(int N);
int isLeftEmpty(DblStack* stack);
int isRightEmpty(DblStack* stack);
int leftPush(DblStack* stack, int data);
int rightPush(DblStack* stack, int data);
int leftPop(DblStack* stack);
int rightPop(DblStack* stack);
int leftPeek(DblStack* stack);
int rightPeek(DblStack* stack);
void printLeftStack(DblStack* stack);
void printRightStack(DblStack* stack);

void getMinPush(struct getMinStack* top, int data);
int getMinPop(struct getMinStack* top);
int getMinPeek(struct getMinStack* top);
int getMinIsEmpty(struct getMinStack* top);
void getMinPrintStack(struct getMinStack* top);
int getMin(struct getMinStack* top);

void enqueue(struct queueNode** back, int data);
int dequeue(struct queueNode** back);
int front(struct queueNode* back);
int back(struct queueNode* back);
int queueIsEmpty(struct queueNode* back);
void printQueue(struct queueNode* back);

void queueStackPush(struct queueStack* qStack, int data);
int queueStackPop(struct queueStack* qStack);
int qStackIsEmpty(struct queueStack* qStack);
int qStackPeek(struct queueStack* qStack);
void printQStack(struct queueStack* qStack);     //prints stack from bottom to top

struct midStack* createEmptyMidStack();
int midIsEmpty(struct midStack* mStack);
void midPush(struct midStack* mStack, int data);
int midPop(struct midStack* mStack);
int midPeek(struct midStack* mStack);
int getMid(struct midStack* mStack);
void deleteMid(struct midStack* mStack);
void printMidStack(struct midStack* mStack);

struct kStacks* createEmptyKStacks();
struct stackNode* createOneOfKStacks(struct kStacks* kStack, int data);      //creates a stack and pushes first element
int pushOntoKStack(struct kStacks* kStack, struct stackNode** top, int data);
int popOffOfKStack(struct kStacks* kStack, struct stackNode** top);
