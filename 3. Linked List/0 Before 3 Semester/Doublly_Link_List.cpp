#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *perivous;
    Node *next;

    // Consturctor
    Node(char data)
    {
        this->data = data;
        perivous = NULL;
        next = NULL;
    }
};

int main()
{
}