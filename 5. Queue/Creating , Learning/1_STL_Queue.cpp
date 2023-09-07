#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue <int> q;

    q.push(0);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();

    cout << "Front : " << q.front() << endl  << "isEmpty : " <<q.empty() << endl;
    q.pop();
}