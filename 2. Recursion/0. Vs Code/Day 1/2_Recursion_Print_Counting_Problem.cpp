#include <iostream>

using namespace std;

void printCount(int n)
{
    if(n==0)
    {
        return ;
    }

    cout << n << " ";

    printCount(n-1)  ;

}


int main()
{
    cout << " Enter Number Count : " ;
    int num ;
    cin >> num ; 

    printCount(num) ;
}