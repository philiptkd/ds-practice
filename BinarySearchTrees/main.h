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

struct listNode
{
    int data;
    struct listNode* prev;
    struct listNode* next;
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

struct listNode* newListNode(int data);

struct treeNode* search(struct treeNode* root, int toFind);
struct treeNode* insert(struct treeNode** root, int toInsert);
void delete(struct treeNode** root, int toDelete);
void findPAndS(struct treeNode* root, int key);
int isBST(struct treeNode* root);
int lowestCommonAncestor(struct treeNode* root, int n1, int n2);
int kthSmallest(struct treeNode* root, int k);
void mergePrint(struct treeNode* root1, struct treeNode* root2);
void printInOrderWStack(struct treeNode* root);
void fixSwapped(struct treeNode* root);
int bstCeil(struct treeNode* root, int key);
int bstFloor(struct treeNode* root, int key);
struct treeNode* dll2bst(struct listNode* head);
int getSize(struct treeNode* root);
void fillArray(struct treeNode* root, int* arr);
void mergeSort(int* arr, int N);
void fillTree(struct treeNode* root, int* arr);
void tree2bst(struct treeNode* root);
struct treeNode* getNextInOrder(struct treeNode** root, struct treeNode** alreadyVisited, struct stackNode** treeStack);
struct treeNode* getNextInReverse(struct treeNode** root, struct treeNode** alreadyVisited, struct stackNode** treeStack);
void pairSum(struct treeNode* root, int X);
struct listNode* bsts2List(struct treeNode* root1, struct treeNode* root2);
struct treeNode* mergeBSTs(struct treeNode* root1, struct treeNode* root2);
