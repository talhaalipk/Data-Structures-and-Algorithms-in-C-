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

void reverseIntArray(int arr[], int size)
{
    // cout << " 11 " << endl ;
    int left = 0, right = size - 1;
    int temp;
    // cout << " 22 " << endl ;
    while (left <= right)
    { 
        // cout << " 77 " << endl ;
        temp = arr[left];

        arr[left] = arr[right];
        arr[right] = temp;


        left += 1;
        right -= 1;
        // cout << " 99 " << endl ;
        cout << left <<" : " << right << endl ;
    }
    // cout << " 33 " << endl ;
}

int main()
{
    const int size = 5;

    int arr[size];

    getIntArray(arr, size);

    printIntArray(arr, size);
     cout << " 1 " << endl ;
    reverseIntArray(arr,size);
     cout << " 2 " << endl ;

    printIntArray(arr, size);

}