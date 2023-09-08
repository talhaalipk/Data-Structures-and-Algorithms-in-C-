#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue <int> q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    reverseQueue(q);

    cout << q.front() << endl ;
    q.pop();
    cout << q.front() << endl ;
    q.pop();
    cout << q.front() << endl ;
    q.pop();
    cout << "Empty : " << q.empty() << endl ;
}