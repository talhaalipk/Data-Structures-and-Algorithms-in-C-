#include <iostream>

using namespace std;

void printNumber(int num, string arr[])
{
    if(num == 0)
    {
        return ;
    }

    int digit = num % 10 ;
    num = num /10 ;

    printNumber(num,arr);

    cout << arr[digit] << "  " ;
    

}

int main()
{

    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "Enter Number : " ;
    int num ;
    cin >> num ;

    printNumber( num,  numbers);
}