#include <iostream>

using namespace std;

int binarySearch(int arr[],int start,int end, int key)
{
    //Base Case
    if(start>end)
    {
        return -1;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key)
    {
        return mid;
    }

    if(key < arr[mid])
    {
        return binarySearch(arr,start,mid-1,key);
    }
    else if(key > arr[mid])
    {
        return binarySearch(arr,mid+1,end,key);
    }
}

int main()
{
    const int size = 7;
    int key = 5 ;

    int sortedArray[size] = {1, 2, 4, 5, 6 , 8 ,10};

    cout << binarySearch(sortedArray,0,size-1,key) ;
}