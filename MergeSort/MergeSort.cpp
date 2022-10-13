/*  Merge sort is an efficient sorting algorithm that produces a STABLE SORT,
    meaning that if two elements have equal values, they hold the same relative
    position in the sorted sequence as they did in the input sequence. Merge
    sort is a comparison sort, which means that it can sort any imput for which
    a 'less-than' relation is defined

    Merge sort is a DIVIDE AND CONQUER ALGORITHM. Like all D&C algorithms, merge
    sort divides a large array into two smaller subarrays and then recursively 
    sorts the subarrays. Basically, two steps are involved in the whole process:

    1. Divide the unsorted array into n subarrays, each of size 1 (an array of 
    size 1 is sorted (trivially, of course)
    2. Repeatedly merge subarrays to produce new sorted subarrays until only 1
    subarray is left, which would be our final sorted array
 */
#include <iostream>
#include <cstdlib>
#include <chrono> //  For time utilities

using namespace std;

#define N 1000

//  Merge two sorted subarrays 'arr[low ... mid]' and 'arr[mid+1 ... high]'
void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    //  While there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }

    //  Copy remaining elements
    while (i <= mid)
    {
        aux[k++] = arr[i++];
    }

    /*  No need to copy the second half (since the remaining items are already
        in their correct position in the auxiliary array)
    */  

    //  Copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++)
    {
        arr[i] = aux[i];
    }
}

//  Sort array 'arr[low ... high]' using auxiliary array 'aux'
void mergesort(int arr[], int aux[], int low, int high)
{
    //  Base case
    if (high <= low) { //  If run size <= 1
        return;
    }

    //  find midpoint
    int mid = (low + ((high - low) >> 1)); //  Shifting right by 1 to divide by 2

    /*  Recursively split runs into two halves until run size <= 1, then merge them
        and return up the call chain
    */
    mergesort(arr, aux, low, mid);      //  Split/merge left half
    mergesort(arr, aux, mid + 1, high); //  Split/merge right half

    Merge(arr, aux, low, mid, high);    //  Merge the two half runs
}

//  Function to check if arr is sorted in non-descending order or not
int isSorted(int arr[])
{
    int prev = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (prev > arr[i])
        {
            cout << "Mergesort fails!" << endl;
            return 0;
        }
        prev = arr[i];
    }

    return 1;
}

//  Implementation of merge sort algorithm in C++
int main()
{
    int arr[N], aux[N];
    srand(time(NULL));

    //  generate random input of integers
    for (int i = 0; i < N; i++)
    {
        aux[i] = arr[i] = (rand() % 100) - 50;
    }

    //  Sort array 'arr' using auxiliary array 'aux'
    mergesort(arr, aux, 0, N - 1);

    if (isSorted(arr))
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}

/*  PERFORMANCE OF MERGE SORT
*   The worst-case time complexity of merge sor is O(nlog(n)), where n is the 
    size of the input. The recurrence relation is:

    T(n) = 2T(n/2) + cn = O(nlog(n))

    The reccurrence basically summarizes the merge sort algorithm - Sort two
    lists of half the original list's size and add the n steps taken to merge
    the resulting two lists.

    The auxiliary space required by the merge sort algorithm is O(n) for the 
    call stack.
*/
