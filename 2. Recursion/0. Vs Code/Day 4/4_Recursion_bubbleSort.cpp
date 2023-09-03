#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSortRecursion(int arr[], int size)
{
    // base case
    if (size == 1)
    {
        return;
    }


    for (int i = 0; i < size-1 ; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i] , arr[i+1]) ;
        }
    }

    bubbleSortRecursion( arr,  size-1) ;
}

int main()
{
    const int size = 8;

    int Array[size] = {7, 4, 3, 4, 2, 1, 5, 6};

    printArray(Array,size) ;

    cout << endl ;

    bubbleSortRecursion(Array,size) ;

    printArray(Array,size) ;
}