#include <iostream>

using namespace std;

void printIntArray(int array[], int size)
{
    cout << " Array : [ ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    // Galti error Puchana ha sir sa
    //cout << "Size Of array : " << sizeof(array) / 4;
}

int main()
{
    const int size = 5;
    int name[size];

    cout << "Size Of array : " << sizeof(name) / 4;

    printIntArray(name, size);

    cout << INT_MIN << endl ;
}