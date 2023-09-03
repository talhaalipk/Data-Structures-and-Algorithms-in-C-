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

void mergeArray(int realArr[], int start, int mid, int end)
{
    int array1_Lenght = mid - start  + 1;
    int array2_Lenght = end - mid;

    int *arr1 = new int[array1_Lenght];
    int *arr2 = new int[array2_Lenght];

    int realArrayIndex = start;

    // copying value in firat array left array from real array
    for (int i = 0; i < array1_Lenght; i++)
    {
        arr1[i] = realArr[realArrayIndex++];
    }

    realArrayIndex = mid + 1;

    // copying value in firat array left array from real array
    for (int i = 0; i < array2_Lenght; i++)
    {
        arr2[i] = realArr[realArrayIndex++];
    }

    // Merging sorted array;
    int i = 0, j = 0, k = start;

    while (i < array1_Lenght && j < array2_Lenght)
    {
        if (arr1[i] < arr2[j])
        {
            realArr[k++] = arr1[i++];
        }
        else
        {
            realArr[k++] = arr2[j++];
        }

        while (i < array1_Lenght)
        {
            realArr[k++] = arr1[i++];
        }
        while (j < array2_Lenght)
        {
            realArr[k++] = arr2[j++];
        }
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int arr[], int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    int mid = start + ((end - start)/ 2);

    // left side recursion call
    mergeSort(arr, start, mid);

    // left side recursion call
    mergeSort(arr, mid + 1, end);

    mergeArray(arr, start, mid, end);
}

int main()
{
    const int size = 5;

    int arr[size] = {5, 3, 2, 6, 4};

    printIntArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printIntArray(arr, size);
}