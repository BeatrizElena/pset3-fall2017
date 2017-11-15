/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
// binary search algorithm requires that array be sorted
bool search(int value, int values[], int n)
{
    int min = 0; // at index 0
    int max = n - 1; // at last index of array
    // eprintf("%d\n", min);
    // eprintf("%d\n", max);

    while (min <= max)
    {
        int mid = (min + max) / 2;
        // eprintf("\nmid: %d\n", mid);

        if (value == values[mid])
        {
            return true;
        }
        else if (value < values[mid])
        {
            max = mid - 1;
            // eprintf("\nmax: %d", max);
        }
        else if (value > values[mid])
        {
            min = mid + 1;
            // eprintf("\nmin: %d", min);
        }
    }
    // needle is not in haystack
    return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swapCounter;
    int i;

    do
    {
        swapCounter = 0;
        for(i = 0; i < n; i++)
        {
            if (values[i] > values[i + 1])
            {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swapCounter++;
            }
        }
    }
    while(swapCounter != 0);
}
