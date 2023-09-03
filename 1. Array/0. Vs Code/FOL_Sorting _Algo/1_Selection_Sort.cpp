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

void selectionSortingIntArray(int arr[] ,int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }   
    }
}

int main()
{
    const int size = 7;

    int array[size];

    getIntArray(array, size);

    printIntArray(array, size);

    selectionSortingIntArray(array,size);

    printIntArray(array, size);
    
}