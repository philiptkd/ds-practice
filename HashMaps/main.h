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
    struct hMapEntry* table;
};

void printTreeVertically(struct treeNode* root);
void printTreeVerticallyRecur(struct treeNode* root, int horizDist, struct hMap* m);
struct hMap* newHashMap(int N);
void hashInsert1(int key, struct hMap* m, int horizDist);
