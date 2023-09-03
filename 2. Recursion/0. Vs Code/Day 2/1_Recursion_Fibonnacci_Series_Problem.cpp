#include <iostream>

using namespace std;

double fibonnacciSeries(int n)
{

    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }

    return fibonnacciSeries(n-1) + fibonnacciSeries(n-2);
}

int main()
{
    int a = fibonnacciSeries(13) ;

    cout << a ;
}