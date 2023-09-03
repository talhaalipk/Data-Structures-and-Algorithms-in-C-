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

void selectionSortIntArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSortIntArray(int arr[], int size)
{
    bool swapStatus = false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapStatus = true;
            }
        }

        if (swapStatus == false)
        {
            break;
        }
    }
}

void insertionSortIntArray(int arr[], int size)
{
    int i = 1;
    while (i < size)
    {
        int temp = arr[i];

        int j = i - 1;
        while (j >= 0)
        {
            if (temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }

        arr[j + 1] = temp;

        i++;
    }
}

int main()
{
    const int even = 6;
    const int old = 7;

    int arrEven[even] = {8,9,4,2,1,3};
    int arrOld[old] = {9,5,4,8,4,1,2};

    //Selection Sort

    // printIntArray(arrEven, even);
    // selectionSortIntArray(arrEven, even);
    // printIntArray(arrEven, even);

    // printIntArray(arrOld, old);
    // selectionSortIntArray(arrOld, old);
    // printIntArray(arrOld, old);

    //Bubble Sort

    // printIntArray(arrEven, even);
    // bubbleSortIntArray(arrEven, even);
    // printIntArray(arrEven, even);

    // printIntArray(arrOld, old);
    // bubbleSortIntArray(arrOld, old);
    // printIntArray(arrOld, old);

    // //Insertion Sort

    printIntArray(arrEven, even);
    insertionSortIntArray(arrEven, even);
    printIntArray(arrEven, even);

    printIntArray(arrOld, old);
    insertionSortIntArray(arrOld, old);
    printIntArray(arrOld, old);
}