
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

void insertionsort(int arr[], int size)
{
    int i = 1 , j  , temp ;

    while(i<size)
    {
        j = i - 1 ;
        temp = arr[i] ;

        while(j>=0 && arr[j] > temp)
        { 
            arr[j+1] = arr[j] ;
            j--;
        }

        arr[j+1] = temp ;

        i++;
    }
}

int main()
{
    int even[6] = {6, 8, 2, 4, 10, 12};
    int old[5] = {9, 7, 5, 3, 1};

    printIntArray(even, 6);
    insertionsort(even,6);
    printIntArray(even, 6);

    printIntArray(old, 5);
    insertionsort(old,5);
    printIntArray(old, 5);
}