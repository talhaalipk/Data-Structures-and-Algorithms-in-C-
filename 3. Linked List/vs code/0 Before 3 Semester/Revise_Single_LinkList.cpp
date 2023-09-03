#include <iostream>

using namespace std;

class Node
{
public:
    float data;
    Node *next;

    Node(float data)
    {
        this->data = data;
    }
};

void printLinkList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " , ";
        temp = temp->next;
    }
    cout << endl;
}

int lenghtLinkList(Node *&head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void insertAtHead(Node *&head, float data)
{
    Node *temp = new Node(data);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, float data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    temp->next = NULL;
    
    tail = temp;
}

int main()
{
    Node *node1 = new Node(10.10);
    node1->next = NULL;

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 20.20);
    insertAtHead(head, 30.30);

    cout << "lenght : " << lenghtLinkList(head) << endl;
    printLinkList(head);

    insertAtTail(tail, 20.20);
    insertAtTail(tail, 30.30);

    cout << "lenght : " << lenghtLinkList(head) << endl;
    printLinkList(head);
}
