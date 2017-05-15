struct fibTreeNode* fibGetMin(struct fibHeap* F);
void fibMerge(struct fibHeap* F, struct fibHeap* G);
void fibInsert(struct fibHeap* F, int key);
int fibExtractMin(struct fibHeap* F);
struct fibHeap* newFibHeap(int key, int maxHeight);
void fibCombineTrees(struct fibHeap* F);
int fibGetHeight(struct fibTreeNode* root);
void fibUpdateMin(struct fibHeap* F);
void fibRemoveMin(struct fibHeap* F, struct fibTreeNode* minNode);
void printFibHeap(struct fibTreeNode* leftTree);
void makeXChildOfY(struct fibTreeNode* newChild, struct fibTreeNode* newParent, struct fibHeap* F, int height);
