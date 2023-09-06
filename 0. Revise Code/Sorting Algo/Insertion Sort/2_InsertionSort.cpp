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

void insertionSort(int arr[], int size)
{
    int i, j, temp;

    i = 1;

    while (i < size)
    {
        temp = arr[i];

        j = i - 1;

        while (j>=0)
        {
            if(temp < arr[j])
            {
                arr[j+1] = arr [j] ;
                j--;
            }
            else
            {
                break;
            }
        }
        
        arr[j+1] = temp ; 

        i++;
    }
}

int main()
{
    const int size = 9;

    int arr[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    printIntArray(arr, size);
    insertionSort(arr, size);
    printIntArray(arr, size);
}