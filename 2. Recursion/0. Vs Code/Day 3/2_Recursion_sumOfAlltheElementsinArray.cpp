#include <iostream>

using namespace std;

long sumOfArray(int arr[], int size)
{
    // base Case return
    if (size <= 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[size-1] ;
    }

    // recursion
    // size --;

    long ans = arr[size-1] + arr[size-2] + sumOfArray(arr,size-2) ;

    return ans;
}

int main()
{
    const int size = 7;

    int sortedArray[size] = {1, 2, 4, 4, 5 , 5 ,10};

    cout << sumOfArray(sortedArray,size) ;
}