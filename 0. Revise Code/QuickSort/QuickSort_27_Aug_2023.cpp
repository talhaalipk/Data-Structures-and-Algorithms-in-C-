#include <iostream>

using namespace std;

/*  Print Array     */

void printArray(int arr[], int size)
{
    cout << "[~   ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << "~]" << endl;
}

/*  splitArray Function     */

int splitArray(int arr[], int start, int end)
{
    int povitValue = arr[start];

    // How many element are greater then povit value
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= povitValue)
        {
            count++;
        }
    }

    // Right povit index
    int rightPovitIndex = start + count;

    // Swap Values

    swap(arr[rightPovitIndex], arr[start]);

    // Make array left side smaller then povit value & right side lager then povit value

    int i = start, j = end;

    while (i < rightPovitIndex && j > rightPovitIndex)
    {
        while (arr[i] <= povitValue)
        {
            i++;
        }
        while (arr[j] > povitValue)
        {
            j--;
        }

        if (arr[i] > povitValue && arr[j] < povitValue)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return rightPovitIndex;
}

/*  Quick Sort      */

void quickSort(int arr[], int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    // Spliting Array
    int povit = splitArray(arr, start, end);

    // Left Side Recursion
    quickSort(arr, start, povit - 1);

    // Right Side Recursion
    quickSort(arr, povit + 1, end);
}

/*  Mian Function   */

int main()
{
    const int size = 10;
    int arr[size] = {2,4,1,6,9 ,9,9,9,9,9};;

    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printArray(arr, size);
}