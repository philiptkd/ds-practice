struct minHeap* createEmptyMinHeap(int size);
int getMin(struct minHeap* h);
int extractMin(struct minHeap* h);
void insertKey(struct minHeap* h, int key);
void deleteKey(struct minHeap* h, int i);
void decreaseKey(struct minHeap* h, int i, int val);
void moveUpHeap(int* arr, int i);
void minHeapify(struct minHeap* h, int i);
void swap(int* x, int* y);
int left(int parent);
int right(int parent);
int parent(int i);
void printHeap(struct minHeap* h);
