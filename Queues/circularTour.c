#include "main.h"
#include <stdio.h>

void nextPump(int* pump, int N);

//the scenario is of a truck making a tour of gas pumps
//if each pump has a different amount of available gas and is
    //a different distance away from the last,
    //this function finds the starting point in the tour that will
        //make it completable
//in the worst case, the correct starting pump is before the initial starting pump,
    //and so will complete after two complete traversals of the array
//so O(n) time. also O(1) extra space.
//input array is of tuples of amount of gas and distance to the next pump
//assumes one unit of gas will take the truck one unit of distance
void circularTour(int tuples[][2], int N)
{
    int tankGas = 0;        //to keep track of the amount of gas in the truck's tank
    int startPump = 0;      //initialize start pump to the first in the given array
    int i = 0;              //an index of the current pump
    int laps = 0;           //to count full traversals of the array. after 2, would be insolvable

    startPump = i;      //record starting point
    do
    {
        while(tankGas < 0 && startPump != i) //if the tank has negative gas, we did not have enough to reach this point
        {
            //retroactively change the starting point
            tankGas = tankGas - tuples[startPump][0] + tuples[startPump][1];
            nextPump(&startPump, N);
        }

        //how much gas the truck would have reaching the next point
        tankGas = tankGas + tuples[i][0] - tuples[i][1];
        nextPump(&i, N);

        if(i == 0)
        {
            laps++;
            if(laps == 2)
                { printf("No solution."); return; }
        }

    }while(i != startPump);

    printf("start: %d", startPump);
}

//to handle incrementing a circular index
void nextPump(int* pump, int N)
{
    if(*pump < N-1)
    {
        *pump = *pump + 1;
    }
    else
    {
        *pump = 0;
    }
}
