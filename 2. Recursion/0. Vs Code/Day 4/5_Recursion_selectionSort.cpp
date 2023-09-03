#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSortRecursion(int *arr, int size)
{
    // base case
    if (size == 1)
    {
        return;
    }


    for (int i = 0; i < size ; i++)
    {
        if(arr[0] > arr[i])
        {
            swap(arr[0] , arr[i]);
        }
    }

    selectionSortRecursion( arr+1,  size-1) ;
}

int main()
{
    const int size = 7;

    int Array[size] = {7, 4, 3, 2, 1, 5, 6};

    printArray(Array,size) ;

    cout << endl ;

    selectionSortRecursion(Array,size) ;

    printArray(Array,size) ;
}