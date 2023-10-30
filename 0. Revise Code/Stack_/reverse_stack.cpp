#include <iostream>
#include <stack>

using namespace std;

void insertAtButtom(stack<int> &s, int value)
{
    if (s.empty())
    {
        s.push(value);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtButtom(s, value);

    s.push(top);
}

void reverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtButtom(s,top);
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
    reverseStack(s);
    printstack(s);
}