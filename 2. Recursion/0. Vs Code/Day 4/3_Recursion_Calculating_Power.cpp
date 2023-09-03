#include <iostream>

using namespace std;

long calculatePower(int num, int pow)
{
    // base case
    if (pow == 0)
    {
        return 1;
    }
    if (pow == 1)
    {
        return num;
    }

    long ans = calculatePower(num, pow / 2);

    if (num % 2 == 1)
    {
        return {num * (ans*ans)};
    }
    if (num % 2 == 0)
    {
        return (ans*ans) ;
    }
    
    return ans;
}

int main()
{
    cout << "Enter the Number : ";
    int a;
    cin >> a;
    cout << "Enter the Power : ";
    int b;
    cin >> b;

    cout << calculatePower(a, b);
}