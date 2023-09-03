#include <iostream>

using namespace std;

bool checkPalindromeString(string& orgStr,string& str, int start, int end)
{
    // Base Case
    if (start > end)
    {
        if(orgStr == str)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    swap(str[start], str[end]);

    bool ans = checkPalindromeString(orgStr, str , start + 1, end - 1);

    return ans;
}

int main()
{
    string name = "balilab";

    int size = name.length();

    string copy = name ;

    cout << checkPalindromeString(name, copy ,  0, size - 1);

}