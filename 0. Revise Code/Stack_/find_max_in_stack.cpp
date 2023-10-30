#include <iostream>
#include <stack>

using namespace std;

int getmax(stack<int> &s)
{
    if(s.empty())
    {
        return -2147483647; // int minnimum
    }

    int top = s.top();
    s.pop();

    int ret_max = getmax(s);

    int max;

    if(ret_max > top)
    {
        max = ret_max;
    }
    else
    {
        max = top ;
    }
    
    s.push(top);
    return max;
}

void printstack(stack<int> s)
{
    cout << "Current Stack : ";

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;

    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    printstack(s);
    cout << "max " << getmax(s) << endl ;
    printstack(s);
}