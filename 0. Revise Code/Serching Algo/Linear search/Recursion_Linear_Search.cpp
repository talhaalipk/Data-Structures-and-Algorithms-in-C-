
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

void linearSearch(int arr[], int start, int end, int key)
{
    // Base Case
    if (start > end)
    {
        cout << "------------- Number do not found -------------" << endl;
        return;
    }

    if (arr[start] == key)
    {
        cout << "------------- Found : " << start << " Index -------------" << endl;
    }
    else
    {
        linearSearch(arr, start + 1, end, key);
    }
}

int main()
{
    int even[6] = {2, 4, 6, 8, 10, 12};
    int old[5] = {1, 3, 5, 7, 9};

    printIntArray(even, 6);

    linearSearch(even, 0, 5, 12);
    linearSearch(old, 0, 4, 7);
}