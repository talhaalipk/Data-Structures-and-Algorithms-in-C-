#include <iostream>
#include <stack>

using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;
    int qSize;

public:
    // Constructor
    Queue()
    {
        qSize = 0;
    }

    /* -- FUNCTIONS -- */
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return qSize;
    }

    void push(int data)
    {
        s1.push(data);
        qSize++;
    }

    void pop()
    {
        // Agar koi elemnt ha he nhi ha
        if (empty())
        {
            cout << "Queue Empty... " << endl;
            return;
        }

        // agar s1 ma to elements para ha magar s2 ma nhi ha
        if (s2.empty())
        {
            int temp;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
        qSize--;
    }

    int front()
    {
        // Agar koi elemnt ha he nhi ha
        if (empty())
        {
            return -111;
        }

        // agar s1 ma to elements para ha magar s2 ma nhi ha
        if (s2.empty())
        {
            int temp;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return (s2.top());
    }
};

void display(Queue &q)
{
    cout << "Empty Status : " << q.empty() << endl ;
    cout << "Front : " << q.front() << endl ;
    cout << "Size : " << q.size() << endl << endl ;
}

int main()
{
    // Queue q;
    // display(q);

    // q.push(10);
    // display(q);

    // q.push(20);
    // display(q);

    // q.push(30);
    // display(q);

    // display(q);
    // q.pop();

    // q.push(40);
    // display(q);

    // display(q);
    // q.pop();

    // display(q);
    // q.pop();

    // display(q);
    // q.pop();

    Queue q;

    q.push(10);

    q.push(20);

    q.push(30);

    cout << q.front() << endl ;
    q.pop(); 

    q.push(40);

    cout << q.front() << endl ;

    q.pop();

    cout << q.front() << endl ;

    q.pop();

    cout << q.front() << endl ;

    q.pop();

    cout << q.front() << endl ;

}