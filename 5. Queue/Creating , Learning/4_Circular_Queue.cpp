#include <iostream>

using namespace std;

class Queue
{
    public:
    int *arr;
    int capacityofQueue;
    int currentSize;
    int front;
    int rear;

public:
    // Constructor//
    Queue(int arrSize)
    {
        arr = new int[arrSize];
        capacityofQueue = arrSize;
        currentSize = 0;
        front = 0;
        rear = 0;
    }

    // Function//

    bool empty()
    {
        if (rear == front )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int capacity()
    {
        return capacityofQueue;
    }

    int size()
    {
        return currentSize;
    }

    int frontq()
    {
        if (front == rear)
        {
            return -111;
        }

        return arr[front];
    }

    int rearq()
    {
        if (front == rear)
        {
            return -111;
        }

        return arr[rear-1];
    }

    void push(int data)
    {
        if ( (front == 0 && rear == capacityofQueue-1) || (front -1 == rear))
        {
            cout << "Queue Full..." << endl;
            return;
        }

        arr[rear] = data;
        currentSize++;
        rear++;
        if(rear == capacityofQueue)
        {
            rear = 0 ;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Queue Empty..." << endl;
            return;
        }

        // Agar empty nhi ha
        front++;
        currentSize--;

        if (front == capacityofQueue)
        {
            front = 0;
        }
    }
};

void DispalyDetails(Queue& q)
{
    cout << "Empty Status : " << q.empty() << endl;
    cout << "fornt : " << q.frontq() << endl;
    cout << "fornt index : " << q.front << endl;
    cout << "rear : " << q.rearq() << endl;
    cout << "rear index : " << q.rear << endl;
    cout << "Capacity : " << q.capacity() << endl;
    cout << "Size : " << q.size() << endl << endl << endl ;
}

int main()
{
    Queue q(3);
    DispalyDetails(q);

    q.push(10);
    DispalyDetails(q);

    q.push(20);
    DispalyDetails(q);

    q.pop();
    DispalyDetails(q);

    q.pop();
    DispalyDetails(q);
    
    // q.push(50);
    // DispalyDetails(q);

    // q.push(60);
    // DispalyDetails(q);

    // q.push(70);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();

    // q.push(10);
    // DispalyDetails(q);

    // q.push(20);
    // DispalyDetails(q);

    // q.push(30);
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    // q.pop();
    // DispalyDetails(q);

    
}