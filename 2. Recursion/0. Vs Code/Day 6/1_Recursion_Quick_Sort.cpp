#include <iostream>

using namespace std;

void printArray(int arr[],int size)
{
    cout << endl << "[ " ;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << "]" << endl;
    
}

int splitArray(int arr[], int start, int end)
{
    // pick first value
    int pivotValue = arr[start];

    int count = 0;

    // counting how much values are smaller then pivotValue
    for (int i = start+1; i <= end; i++)
    {
        if (arr[i] <= pivotValue)
        {
            count++;
        }
    }

    // Right index of pivotValue
    int rightPivotIndex = start + count;

    swap(arr[start], arr[rightPivotIndex]);

    int i = start, j = end;

    while (i < rightPivotIndex && j > rightPivotIndex)
    {
        while (arr[i] <= pivotValue)
        {
            i++;
        }
        while (arr[j] > pivotValue)
        {
            j--;
        }

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    return rightPivotIndex;
}

void quickSortRecursion(int arr[], int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    // Calling function to crete 2 parts of array
    int pivot /*mid*/ = splitArray(arr, start, end);

    // Recursion for left array partition
    quickSortRecursion(arr, start, pivot - 1);
    // Recursion for right array partition
    quickSortRecursion(arr, pivot + 1, end);

}

int main()
{
    const int size = 6;
    int arr[size] = { 6, 5, 4, 3, 2, 1};

    printArray(arr,size);

    quickSortRecursion(arr,0,size-1);

    printArray(arr,size);

}