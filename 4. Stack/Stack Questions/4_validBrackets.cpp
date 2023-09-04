#include <iostream>
#include <stack>

using namespace std;

bool checkValidBrackets(string str)
{
    // Agar string Khali ho
    if (str.empty())
    {
        cout << "String is Empty " << endl;

        return 0;
    }

    stack<int> s;
    char ch, check;

    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];

        if (ch == '[' || ch == '{' || ch == '(')
        {
            s.push(ch);
        }

        if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                check = s.top();

                if ((ch == ')' && check == '(') || (ch == '}' && check == '{') || (ch == ']' && check == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    /*  Test inputs
    ->>  [()]{}{[()()]()}
    ->>  [[}[
    */
    string s = "[[}[";

    if (checkValidBrackets(s))
    {
        cout << "Valid " << endl;
    }
    else
    {
        cout << "Not Valid " << endl;
    }
}