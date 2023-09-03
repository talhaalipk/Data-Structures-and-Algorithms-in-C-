
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

void binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            cout << "Number Found at  index : " << mid << endl;
            return ;
        }

        //
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

         mid = start + (end - start) / 2;
    }

    cout << "----------Number do not Found ----" << endl ;
}

int main()
{
    int even[6] = {2, 4, 6, 8, 10, 12};
    int old[5] = {1, 3, 5, 7, 9};

    printIntArray(even, 6);

    binarySearch(even , 6 , 4) ;
    binarySearch(old , 5 , 65) ;

}