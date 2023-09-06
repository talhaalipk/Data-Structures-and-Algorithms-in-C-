
#include <iostream>

using namespace std;

void printIntArray(int array[], int size)
{
    cout << "Array : [ ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

void getIntArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

int splitArray(int arr[], int s, int e)
{
    int letIndex = s;

    int midvalue = arr[letIndex];

    int count = 0;

    for (int i = s+1; i <= e; i++)
    {
        if (midvalue >= arr[i])
        {
            count++;
        }
    }

    int rightIndex =   letIndex +  count;

    // To set value at position
    swap(arr[rightIndex], arr[letIndex]);

    // mid lift side smaller and right slide greater
    int i = s, j = e;

    while (i < rightIndex && j > rightIndex)
    {
        while (arr[i] <= midvalue)
        {
            i++;
        }
        while (arr[j] > midvalue)
        {
            j--;
        }
        if (i < rightIndex && j > rightIndex)
        {
            if (arr[i] > midvalue && arr[j] < midvalue)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
    }

    return rightIndex;
}

void quickSort(int arr[], int start, int end)
{
    // base Case
    if (start >= end)
    {
        return;
    }

    // spliting array

    int povit = splitArray(arr, start, end);

    // left recursion
    quickSort(arr, start, povit - 1);
    // Right recursion
    quickSort(arr, povit + 1, end);
}

int main()
{
    int even[6] = {6, 8, 2, 4, 10, 12};
    int old[5] = {9, 7, 5, 3, 1};

    printIntArray(even, 6);
    quickSort(even, 0, 5);
    printIntArray(even, 6);

    printIntArray(old, 5);
    quickSort(old, 0, 4);
    printIntArray(old, 5);
}