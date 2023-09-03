#include <iostream>

using namespace std;

class Stack
{
    // Member variable
    int *arr;
    int sizeOfArray;
    int top1;
    int top2;

public:
    // constructor
    Stack(int size)
    {
        this->arr = new int[size];
        sizeOfArray = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if(top2 - top1 > 1)
        {
            top1++ ;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack overflow " << endl;
        }
    }

    void push2(int data)
    {
        if(top2 - top1 > 1)
        {
            top2-- ;
            arr[top2] = data;
        }
        else
        {
            cout << "Stack overflow " << endl;
        }
    }

    int pop1()
    {
        if(top1 > -1)
        {
            int ans = arr[top1];
            top1--;

            return ans;
        }
        else
        {
            cout << "Stack empty " << endl;
            return 55555;
        }
    }

    int pop2()
    {
        if(top2 < sizeOfArray)
        {
            int ans = arr[top2];
            top2++;

            return ans;
        }
        else
        {
            cout << "Stack empty " << endl;
            return 55555;
        }
    }

};

int main()
{
    Stack* s1 = new Stack(5);

    s1->push1(5);
    s1->push2(10);
    s1->push1(15);
    s1->push2(20);
    s1->push1(25);
    s1->push2(30);
    s1->push1(35);

    cout << s1->pop1() << endl ;
    cout << s1->pop2() << endl ;
    cout << s1->pop1() << endl ;
    cout << s1->pop2() << endl ;
    cout << s1->pop1() << endl ;
    cout << s1->pop2() << endl ;
    cout << s1->pop1() << endl ;

}