#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    // Array
    const int size = 10;
    int arr_num[size];

    cout << "Array : " ;
    for (int i = 0; i < size; i++)
    {
        arr_num[i] = rand() % 100 ;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr_num[i] << " " ;
    }

    cout << endl ;

    */

    int arr[3] = {1, 2, 3};

    cout << &arr << endl;
    int *ptr = arr;

    cout << ptr << endl;
    cout << *ptr << endl;

    // not working 
    
    ptr = (ptr + 4);

    cout << ptr << endl;
    cout << *ptr << endl;
}