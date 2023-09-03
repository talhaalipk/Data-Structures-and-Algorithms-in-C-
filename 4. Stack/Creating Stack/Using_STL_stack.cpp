#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stack;

    if (stack.empty())
    {
        cout << "Stack is Empty " << endl;
    }
    else
    {
        cout << "Stack is not Empty " << endl;
    }
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    if (stack.empty())
    {
        cout << "Stack is Empty " << endl;
    }
    else
    {
        cout << "Stack is not Empty " << endl;
    }

    stack.pop();
    cout << "Top : " << stack.top() << endl ;
    cout << "Size : " << stack.size() << endl ;

    stack.pop();
    cout << "Top : " << stack.top() << endl ;
    cout << "Size : " << stack.size() << endl ;

    stack.pop();
    cout << "Top : " << stack.top() << endl ;
    cout << "Size : " << stack.size() << endl ;

    stack.pop();
    cout << "Top : " << stack.top() << endl ;
    cout << "Size : " << stack.size() << endl ;


    if (stack.empty())
    {
        cout << "Stack is Empty " << endl;
    }
    else
    {
        cout << "Stack is not Empty " << endl;
    }
}