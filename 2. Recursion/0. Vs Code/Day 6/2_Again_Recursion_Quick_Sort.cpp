#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    cout << endl
         << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int make2Array(int arr[], int start, int end)
{
    // first value as povit value
    int povitValue = arr[start];

    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= povitValue)
        {
            count++;
        }
    }

    int povitIndex = start + count;

    swap(arr[start], arr[povitIndex]);

    int i = start, j = end;

    while (i < povitIndex && j > povitIndex)
    {
        while (arr[i] <= povitValue)
        {
            i++;
        }

        while (arr[j] > povitValue)
        {
            j++;
        }

        if(arr[i] > povitValue && arr[j] < povitValue)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return povitIndex ;
}

void quickSortRecursion(int arr[], int start, int end)
{
    // Stop Cond..
    if (start >= end)
    {
        return;
    }

    int povit = make2Array(arr, start, end);

    // Left sort
    quickSortRecursion(arr, start, povit - 1);
    // right sort
    quickSortRecursion(arr, povit + 1, end);
}

int main()
{
    const int size = 5;
    int arr[size] = {5, 4, 4, 2, 1};

    printArray(arr, size);

    quickSortRecursion(arr, 0, size - 1);

    printArray(arr, size);
}