struct binomialTreeNode* unionBinHeaps(struct binomialTreeNode* H, struct binomialTreeNode* G);
struct binomialTreeNode* mergeHeaps(struct binomialTreeNode* H, struct binomialTreeNode* G);
int getHeight(struct binomialTreeNode* H);
void binInsert(struct binomialTreeNode** H, int k);
struct binomialTreeNode* createNewHeap(int k);
struct binomialTreeNode* binGetMin(struct binomialTreeNode* H);
int binExtractMin(struct binomialTreeNode** H);
void reverseHeap(struct binomialTreeNode** H);
void removeTree(struct binomialTreeNode** H, struct binomialTreeNode* treeNode);
void printBinomialHeap(struct binomialTreeNode* H);
