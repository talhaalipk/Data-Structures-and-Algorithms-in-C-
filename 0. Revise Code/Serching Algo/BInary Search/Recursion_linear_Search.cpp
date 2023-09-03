
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

void binarySearch(int arr[], int start, int end, int key)
{
    if(start > end)
    {
        cout << "------------- Number do not found -------------" << endl ;
        return ;
    }
        
    int mid = start +( end - start )/ 2 ;

    if(arr[mid] == key)
    {
        cout << "------------- Found : " << mid << " Index -------------" << endl ;
        return ;
    }

    //recursion
    if(key < arr[mid])
    {
        end = mid -1 ;
        binarySearch(arr,start , end , key) ;
    }
    else
    {
        start = mid + 1 ;
        binarySearch(arr,start , end , key) ;
    }
    
}

int main()
{
    int even[6] = {2, 4, 6, 8, 10, 12};
    int old[5] = {1, 3, 5, 7, 9};

    printIntArray(even, 6);

    binarySearch(even ,0 , 5 , 4) ;
    binarySearch(old , 0,4 , 7) ;

}