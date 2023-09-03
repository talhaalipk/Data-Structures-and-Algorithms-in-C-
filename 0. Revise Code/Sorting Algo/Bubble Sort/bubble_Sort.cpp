
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

void bubbleSort(int arr[], int size)
{
    bool status = true ;
    for(int i=0 ; i < size - 1 ; i++)
    {
        for (int j = 0 ; j < size - 1 - i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);

                status = false ;
            }
        }

        if ( status == true)
        {
            return ;
        }
        
    }
}

int main()
{
    int even[6] = {6, 8, 2, 4, 10, 12};
    int old[5] = {9, 7, 5, 3, 1};

    printIntArray(even, 6);
    bubbleSort(even,6);
    printIntArray(even, 6);

    printIntArray(old, 5);
    bubbleSort(old,5);
    printIntArray(old, 5);
}