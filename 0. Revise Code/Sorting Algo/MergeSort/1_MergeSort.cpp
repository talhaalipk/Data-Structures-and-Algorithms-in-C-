
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

void mergeTwoSortedArray(int arr[], int start, int end)
{
    int mid = (start + end ) / 2;

    int size1 = mid - start + 1;
    int size2 = end - mid;


    // First Array
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    int k = start;

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;

    // Second Array

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[k++];
    }

    /*Merging Algo*/
    int i = 0 ;
    int j = 0 ,
     y = start;

    while (i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j])
        {
            arr[y++] = arr1[i++] ;
        }
        else
        {
            arr[y++] = arr2[j++] ;
        }    

        
    }

    while(i<size1)
    {
        arr[y++] = arr1[i++] ;
    }
    while(j<size2)
    {
        arr[y++] = arr2[j++] ;
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int arr[], int start, int end)
{
    // base case
    if (start >= end) // jan srif ak element of array ma
    {
        return;
    }

    // Find mid to split Array
    int mid = (start + end ) / 2;

    // RECURSION START

    // for left side
    mergeSort(arr, start, mid);

    // for right side
    mergeSort(arr, mid + 1, end);

    // NOW MERGE BOTH ARRAY
    mergeTwoSortedArray(arr, start, end);
}

int main()
{
    int even[6] = {6, 8, 2, 4, 10, 12};
    int old[5] = {9, 7, 5, 3, 1};

    printIntArray(even, 6);
    mergeSort(even, 0, 5);
    printIntArray(even, 6);

    printIntArray(old, 5);
    mergeSort(old, 0, 4);
    printIntArray(old, 5);

    return 0;
}

// int main() {

//     int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
//     int n = 15;

//     mergeSort(arr, 0, n-1);

//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     } cout << endl;

//     return 0;
// }