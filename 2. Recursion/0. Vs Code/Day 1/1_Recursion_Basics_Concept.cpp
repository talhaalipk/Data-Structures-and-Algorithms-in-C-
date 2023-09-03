#include <iostream>

using namespace std;

int name(int n)
{
    //Base Case
    if(n == 0)
    {
        return 1;
    }

    // Recursion 
    return n * name(n) ;
}

int main()
{
    
}   