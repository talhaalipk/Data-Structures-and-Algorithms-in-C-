#include <iostream>

using namespace std;

void reverseString(string &str, int start, int end)
{
    // cout << "AA gya " << endl;
    // Base Case
    if (start > end)
    {
        return;
    }

    swap(str[start], str[end]);

    reverseString(str, start + 1, end - 1);
}

int main()
{
    string name = "Talha Ali";

    int size = name.length();

    cout << name << endl;

    reverseString(name, 0, size - 1);

    cout << name << endl;
}