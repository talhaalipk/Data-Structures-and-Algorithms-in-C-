#include <iostream>

using namespace std;

int linearSearch(int arr[],int size,int key)
{
    if(size==0)
    {
        return -1;
    }

    if(arr[size-1] == key)
    {
        return size-1;
    }
    else{
        return linearSearch(arr,size-1,key);
    }
}

int main()
{
    const int size = 5;
    int key =  2 ;
    int sortedArray[size] = {1, 2, 4, 4, 5 };

    cout << linearSearch(sortedArray,size,key) ;


}