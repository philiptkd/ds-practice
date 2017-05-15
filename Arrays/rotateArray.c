//rotates an array to the left in O(n) time and O(1) auxiliary memory
//arr[] : array to be rotated
//N : length of arr[]
//d : places to rotate by
//assumes d < N

void swapElems(int arr[], int x, int y);
void printList(int arr[], int left, int right);

void rotateArray(int arr[], int N, int d)
{
    int i = 0;  //index of arr we are swapping FROM
    int j = -1;  //index of arr we have just swapped TO
    int k = i;  //original index of current element under consideration
    //(directionality of a swap is defined in that the position we swap TO now necessarily has the correct rotated value)
    int count = 0;  //number of swaps we have made

    while(count < N)
    {
        j = k-d;        //the correct rotated position of the value currently at index i
        if(j < 0){ j = j+N; }   //since d<N, could not have been less than -N + 1. so 0 < j+N < N
        swapElems(arr, i, j);   //swap element from i into its correct position, j
        k = j;
        if(j == i)      //if we have just swapped an element into its own previous position, increment i to avoid a loop
        {
            i++;
            k++;
        }
        count++;
    }
    printList(arr, 0, N-1);
}
