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

void bubbleSortingIntArray(int arr[] ,int size)
{
    for (int i = 0; i < size-1; i++)
    {
        bool swapStatus = false ;
        for (int j = 0; j < (size-1)-(i); j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapStatus = true ;
            }
        }

        if(swapStatus == false)
        {
            break;
        }   
    }
}

int main()
{
    const int size = 7;

    int array[size];

    getIntArray(array, size);

    printIntArray(array, size);

    bubbleSortingIntArray(array,size);

    printIntArray(array, size);
    
}