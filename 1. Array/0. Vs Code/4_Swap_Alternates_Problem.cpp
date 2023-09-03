#include <iostream>

using namespace std;

void printIntArray(int array[], int size)
{
    cout << " Array : [ ";
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


//standed Aproch
void alternateSwapIntArray(int arr[], int size)
{
    for(int i=0; i< size ; i = i + 2)
    {
        if (i+1 < size)
        {
            swap(arr[i] , arr[i+1]);
        }
    }
}

int main()
{
    const int size = 5;

    int arr[size];

    getIntArray(arr, size);

    printIntArray(arr, size);

    alternateSwapIntArray(arr,size);

    printIntArray(arr, size);
}