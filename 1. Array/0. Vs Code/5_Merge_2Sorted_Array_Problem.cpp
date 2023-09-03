#include <iostream>

using namespace std;

void print(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void merge(int arr1[], int s1, int arr2[], int s2, int sortedarray[])
{
    int i = 0, j = 0, k = 0;

    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
        {
            sortedarray[k++] = arr1[i++];
        }
        else
        {
            sortedarray[k++] = arr2[j++];
        }
    }

    while (i < s1)
    {
        sortedarray[k++] = arr1[i++];
    }
    while (j < s2)
    {
        sortedarray[k++] = arr2[j++];
    }
}

int main()
{

    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

    int arr3[10 + 30] = {0};

    merge(arr1, 10, arr2, 30, arr3);

    print(arr3, 40);
}