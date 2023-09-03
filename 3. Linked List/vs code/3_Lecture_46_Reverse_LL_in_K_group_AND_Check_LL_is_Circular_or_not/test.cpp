#include <iostream>

using namespace std;

class Node
{
public:
    // Data Members
    int data;
    Node *next;

    // Constructor
    Node(int num)
    {
        this->data = num;
        this->next = NULL;
    }
};

int main()
{
    Node *ab = new Node(10) ;

    cout << ab->data << endl ;
    // cout << ab->next << endl 

    Node *ptr =  ab->next->next ;

    if(ptr == NULL)
    {
        cout << "print" << endl ;
    }
    else
    {
        cout << "sjksf" << endl; 
    }
}