/*
KEY POINTS

1 -> Must be sorted Array (assend. , deassend)
2 ->  Formula <-::-> mid = start + ((end - start) / 2);

*/

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

int binarySearchIntArray(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
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

    return -1;
}

void resultBinarySearchIntArray(int arr[], int size, int key)
{
    int returnValue = binarySearchIntArray(arr,size,key);

    if (returnValue == -1)
    {
        cout << "Element not Found in Array " << endl;
    }
    else
    {
        cout << "Element Found on Index " << returnValue << " in Array " << endl;

    }
}

int main()
{
    int even[6] = {2, 4, 6, 8, 10, 12};
    int old[5] = {1, 3, 5, 7, 9};

    printIntArray(even, 6);

    resultBinarySearchIntArray(even , 6 , 8);

    printIntArray(old, 5);
    resultBinarySearchIntArray(old , 5 , 7);    
}