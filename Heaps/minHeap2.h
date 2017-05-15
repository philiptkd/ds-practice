struct minHeap* createEmptyMinHeap2(int size);
int* getMin2(struct minHeap* h);
int* extractMin2(struct minHeap* h);
void insertKey2(struct minHeap* h, int key, int val2);
void deleteKey2(struct minHeap* h, int i);
void decreaseKey2(struct minHeap* h, int i, int val);
void moveUpHeap2(int* arr, int i);
void minHeapify2(struct minHeap* h, int i);
void swap2(int* x, int* y);
int left2(int parent);
int right2(int parent);
int parent2(int i);
void printHeap2(struct minHeap* h);
