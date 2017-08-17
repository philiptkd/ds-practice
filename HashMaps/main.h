struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct hMapEntry
{
    int key;
    int hashInput;
    struct hMapEntry* next;
};

struct hMap
{
    int N;
    int numItems;
    struct hMapEntry* table;
};

struct listNode
{
    int data;
    struct listNode* next;
    struct listNode* prev;
};

struct treeNode* newNode(int data);

void printTreeVertically(struct treeNode* root);
void printTreeVerticallyRecur(struct treeNode* root, int horizDist, struct hMap* m, int* minHorizDist, int* maxHorizDist);
struct hMap* newHashMap(int N);
void hashInsert(int key, struct hMap* m, int horizDist);
int hashFn(int input, int tableSize);
void reHash(struct hMap* oldMap, struct hMap* newMap);

int isArrSubset(int* arr1, int N1, int* arr2, int N2);

struct listNode* newListNode(int data);
void append2List(struct listNode** circList, int data);
void printCircularList(struct listNode* head);
void unionAndIntersection(struct listNode* list1, struct listNode* list2);

int checkForSum(int* arr, int N, int X);

int duplicatesWithinK(int* arr, int N, int k);
