#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue <int> &q)
{
    //Base Case
    if(q.empty())
    {
        return; 
    }

    int fornt = q.front();
    q.pop();

    //Recursion Call
    reverseQueue(q);

    q.push(fornt);
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