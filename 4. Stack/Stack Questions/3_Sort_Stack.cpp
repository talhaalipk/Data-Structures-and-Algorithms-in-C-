/*  SORT STACK  */

#include <iostream>
#include <stack>

using namespace std;

void insertAtRightPlace(stack<int> &s, int valueToInsert)
{
    // base case koi choti value nhi ha
    if (s.empty())
    {
        s.push(valueToInsert);
        return;
    }

    if (s.top() <= valueToInsert)
    {
        s.push(valueToInsert);
        return;
    }


    int top = s.top();
    s.pop();

    insertAtRightPlace(s,valueToInsert);

    s.push(top) ;
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    // store element
    int top = s.top();
    s.pop();

    // recursive call
    sortStack(s);

    // To insert --- int top = s.top();--- at right place
    insertAtRightPlace(s, top);
}

int main()
{
    stack<int> s;

    s.push(20);
    s.push(10);
    s.push(8);
    s.push(8);
    s.push(2);
    s.push(-3);

    sortStack(s);


    while(!s.empty())
    {
        cout << s.top() << endl ;
        s.pop() ;
    }
}