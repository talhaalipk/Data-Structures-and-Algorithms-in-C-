#include <iostream>

using namespace std;

bool isSortedArray(int arr[], int size)
{
    // base Case return
    if (size <= 0)
    {
        return true;
    }

    // recursion
    size --;
    // size = size -1 ; //wrong code find error 
    // cout << size << endl ;
    bool ans = arr[size-1] <= arr[size] && isSortedArray(arr,size) ;

        return ans;
}

int main()
{
    const int size = 5;

    int sortedArray[size] = {1, 2, 4, 4, 5};

    cout << isSortedArray(sortedArray,size) ;
}