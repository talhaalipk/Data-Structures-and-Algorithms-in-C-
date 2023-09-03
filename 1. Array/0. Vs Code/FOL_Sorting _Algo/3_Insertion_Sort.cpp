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

void insertionSortingIntArray(int arr[] ,int size)
{
    int i = 1;
    while(i<size)
    {
        int temp = arr[i];

        int j=i-1;
        while(j >= 0)
        {
            if(temp < arr[j])
            {
                arr[j+1] = arr[j] ;
            }
            else
            {
                break;
            }
            j--;
        }
        
        cout << "j = " << j << endl ;
        
        arr[j+1] = temp ;

        i++;
    }
}

int main()
{
    const int size = 7;

    int array[size];

    getIntArray(array, size);

    printIntArray(array, size);

    insertionSortingIntArray(array,size);

    printIntArray(array, size);
    
}