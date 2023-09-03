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

void bubbleSortIntArray(int arr[], int size)
{
    bool swapStatus = false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapStatus = true;
            }
        }

        if (swapStatus == false)
        {
            break;
        }
    }
}

void linearSearchIntArray(int arr[], int size, int key)
{
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Number Donot Found " << endl;
    }
    else
    {
        cout << "Number Found at " << index << " Index." << endl;
    }
}

int binarySearchIntArray(int arr[], int size, int key)
{
    bubbleSortIntArray(arr,size);

    int start = 0;
    int end = size - 1;
    int index = -1;
    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
            // index = mid;
            // break;
        }

        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + ((end - start) / 2);
    }

    return -1 ;
    // if (index == -1)
    // {
    //     cout << "Number Donot Found " << endl;
    // }
    // else
    // {
    //     cout << "Number Found at " << index << " Index." << endl;
    // }
}

int main()
{
    const int even = 6;
    const int old = 7;

    int arrEven[even] = {8, 9, 4, 2, 1, 3};
    int arrOld[old] = {9, 5, 4, 8, 4, 1, 2};

    cout << binarySearchIntArray(arrEven, even, 2);
    cout << binarySearchIntArray(arrOld, old, 2);
}