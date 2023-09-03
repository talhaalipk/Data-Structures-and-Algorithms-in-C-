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

int linearSearchIntArray(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int size = 10;

    int array[size];

    getIntArray(array, size);

    printIntArray(array, size);

    cout << "Enter Element you want to Search in Array : ";
    int key;
    cin >> key;

    int returnValue = linearSearchIntArray(array, size, key);
    if (returnValue == -1)
    {
        cout << "Element not Found in Array " << endl;
    }
    else
    {
        cout << "Element Found on Index " << returnValue << " in Array " << endl;
    }
}