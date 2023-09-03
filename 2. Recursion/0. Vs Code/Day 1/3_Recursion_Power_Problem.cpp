#include <iostream>

using namespace std;

int powerof2(int n)
{
    //Base Case
    if(n==0)
    {
        return 1 ;
    }

    return 2 * (powerof2(n-1)) ;
}   

int main()
{
    cout << "Enter power of 2 : " << endl ;
    int pow;
    cin >> pow ;

    cout << powerof2(pow);
}