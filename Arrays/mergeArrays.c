//merges two arrays into the larger array with missing elements
//assumes M > N
//"missing" elements in mArr are given values of -1
//assumes there are exactly N missing elements in mArr
//assumes both input arrays are sorted and of nonnegative integers
//merges so that mArr remains sorted
//does so in constant space

void printList(int arr[], int left, int right);
void swapElems(int arr[], int x, int y);

void mergeArrays(int nArr[], int N, int mArr[], int M)
{
    //move all "real" values to end of mArr
    int end = M-1;
    int i;
    for(i = end; i >= 0; i--)
    {
        if(mArr[i] > 0)
        {
            //swap elements at i and end
            swapElems(mArr, i, end);
            end--;
        }
    }
    end++;  //this variable now holds the starting index of the "real" values originally in mArr

    int nIndex = 0;
    int mIndex = 0;
    while(nIndex < N)
    {
        //if nArr has the lower element, insert it into mArr
        if(nArr[nIndex] < mArr[end])
        {
            mArr[mIndex] = nArr[nIndex];
            nIndex++;
            mIndex++;
        }
        //else, move the next lowest element in mArr as far left as possible
        else
        {
            swapElems(mArr, mIndex, end);
            mIndex++;
            end++;
        }
    }

    printList(mArr,0,M-1);
}
