//given two sorted arrays, each of length N, finds the median of the merged array
//does not actually merge arrays, as that takes at least O(n) time
//finding the merged median takes O(log n) time
//the idea is to compare the medians of each input array and eliminate impossible candidates for the merged median

float mergedMedian(int arrA[], int arrB[], int N)
{
    float medA, medB;
    int leftA = 0;
    int rightA = N-1;
    int leftB = 0;
    int rightB = N-1;

    while(leftA < rightA)       //could also be while leftB < rightB
    {
        int len = rightA-leftA+1;   //length of current subarrays

        if(len == 2)
        {
            //if we merged these two subarrays, the leftA/B elements would be on the left side and the rightA/B on the right
            //we want the average of the centermost two, so we choose the largest left and smallest right
            int maxLower, minUpper;
            if(arrA[leftA] > arrB[leftB])
                maxLower = arrA[leftA];
            else
                maxLower = arrB[leftB];

            if(arrA[rightA] < arrB[rightB])
                minUpper = arrA[rightA];
            else
                minUpper = arrB[rightB];

            return (maxLower + minUpper)/2.0;
        }
        else if(len%2 == 0)        //if there are an even number of elements in each array, the median is an average of two elements
        {
            medA = (arrA[leftA + len/2] + arrA[leftA + len/2 - 1])/2.0;
            medB = (arrB[leftB + len/2] + arrB[leftB + len/2 - 1])/2.0;

            //if the medians are the same, they have the same # of values to their left as to their right
                //so they are equal to the merged median
            if(medA == medB)
                return medA;

            //values lower than the lower median cannot be the merged median
                //bc they could not have an equal # of values to their left and right in the merged array
                //similarly, values higher than the higher median cannot be the merged median
            if(medA < medB)
            {
                leftA = leftA + len/2 - 1;
                rightB = rightB - len/2 + 1;
            }
            else
            {
                leftB = leftB + len/2 - 1;
                rightA = rightA - len/2 + 1;
            }
        }
        else    //the length of the subarrays is odd
        {
            medA = arrA[leftA + len/2];
            medB = arrB[leftB + len/2];

            if(medA == medB)
                return medA;

            if(medA < medB)
            {
                leftA = leftA + len/2;
                rightB = rightB - len/2;
            }
            else    //if medB < medA
            {
                leftB = leftB + len/2;
                rightA = rightA - len/2;
            }
        }
    }

    return -1;
}
