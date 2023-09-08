#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    //Constructor
    Node(int d)
    {
        data = d;
        next =  NULL;
    }
};

class Queue
{
    Node *qFront;
    Node *qRear; 
    int qSize;

public:
    Queue()
    {
        qFront = NULL;
        qRear = NULL;
        qSize = 0 ;
    }

    int size()
    {
        return qSize;
    }

    void push(int data)
    {
        if(qFront == NULL)
        {
            Node* temp = new Node(data);
            qSize++;
            qFront = temp ;
            qRear = temp ;
        }
        else
        {
            Node* temp = new Node(data);
            qSize++;
            qRear->next = temp ;
            qRear = temp ;
        }
    }

    void pop()
    {
        if(qFront == NULL)
        {
            cout << "Empty Queue... " << endl ;
        }
        else
        {
            Node *tempdelete = qFront;

            qFront = qFront->next;
            qSize--;
            delete tempdelete;
        }
    }

    bool empty()
    {
        if(qFront == NULL)

            return 1 ;
        else
            return 0;
    }

    int front()
    {
        if(empty())
        {
            return -1111;
        }
        else
        {
            return qFront->data ;
        }
    }

    int rear()
    {
        if(empty())
        {
            return -1111;
        }
        else
        {
            return qRear->data ;
        }
    }
};

void display(Queue& q)
{
    cout << "Empty Status : " << q.empty() << endl;
    cout << "fornt : " << q.front() << endl;
    cout << "rear : " << q.rear() << endl;
    cout << "Size : " << q.size() << endl << endl << endl ;
}

int main()
{
    Queue q;
    display(q);

    q.push(10);
    display(q);

    q.push(20);
    display(q);

    q.push(30);
    display(q);

    q.pop();
    display(q);

    q.pop();
    display(q);

    q.pop();
    display(q);

    q.push(10);
    display(q);

    q.push(20);
    display(q);

    q.push(30);
    display(q);

    q.pop();
    display(q);

    q.pop();
    display(q);

    q.pop();
    display(q);

}