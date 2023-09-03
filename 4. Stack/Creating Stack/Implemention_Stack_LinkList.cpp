#include <iostream>

using namespace std;

class Node
{
public:
    // Data Membmers
    int data;
    Node *next;
    // Constructor

    Node(int d) : data(d) {}
    // Destructor
    ~Node() {}
};

class Stack
{
protected:
    // Data Membmers
    Node *topNode;
    int sizeOfStack;

public:
    // Constructor
    Stack()
    {
        topNode = NULL;
        sizeOfStack = 0;
    }
    // Functions

    /*Puch Function*/
    void push(int d)
    {
        // certing node
        Node *temp = new Node(d);
        // incresing size;
        ++sizeOfStack; // by 1

        // make node connection of nodes
        temp->next = topNode;

        topNode = temp;
    }

    /*Pop Function*/
    void pop()
    {
        if (topNode == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        Node* temp = topNode ;

        topNode = topNode ->next ;

        // Decrease size ;
        --sizeOfStack;

        // deleting node
        temp ->next = NULL ;
        delete temp;
    }

    /*Size function*/
    int size()
    {
        return sizeOfStack;
    }

    /*empty function*/
    bool empty()
    {
        if(topNode == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    /*Top Function*/
    int top()
    {
        if (topNode == NULL)
        {
            cout << "Stack is Empty" << endl;
            return 99999;
        }

        int data = topNode->data ;

        return data;
    }

    // Destructor
    ~Stack()
    {
        cout << endl
             << "Object deleted " << endl;
    }
};

int main()
{
    Stack* stack = new Stack;

    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;

    stack->push(10);
    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;

    stack->push(20);
    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;

    stack->push(30);
    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;

    stack->pop();
    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;

    stack->pop();
    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;

    stack->pop();
    cout << endl <<  "Empty : " << stack->empty() << endl ;
    cout << "Top : " << stack->top() << endl ;
    cout << "Size : " << stack->size() << endl ;


}