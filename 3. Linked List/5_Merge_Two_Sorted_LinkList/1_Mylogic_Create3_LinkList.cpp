#include <iostream>

using namespace std;

// ============================================================================ //
// ==============Create Node Class============================================= //
// ============================================================================ //
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

// ============================================================================ //
// ==============Lenght of Link List=========================================== //
// ============================================================================ //

int lenghtofLinkList(Node *&head)
{
    Node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// ============================================================================ //
// ==============Insert At Head================================================ //
// ============================================================================ //

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    temp->next = head;

    head = temp;
}

// ============================================================================ //
// ==============Insert At Tail================================================ //
// ============================================================================ //

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;

    tail = temp;
}

// ============================================================================ //
// ==============Insert At Any Postion========================================= //
// ============================================================================ //

void insertAtAnyPostion(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);

        return;
    }
    if (position == lenghtofLinkList(head) + 1)
    {
        insertAtTail(tail, data);

        return;
    }
    if (position > lenghtofLinkList(head))
    {
        cout << "Position is not in link list " << endl;

        return;
    }

    Node *temp = head;
    int pos = 1;

    while (pos < position - 1)
    {
        temp = temp->next;
        pos++;
    }

    Node *insertNode = new Node(data);

    insertNode->next = temp->next;
    temp->next = insertNode;
}

// ============================================================================ //
// ==============Delate Any Postion============================================ //
// ============================================================================ //

void DeleteAnyPostion(Node *&head, Node *&tail, int position)
{
    if (position > lenghtofLinkList(head))
    {
        cout << "Position is not in link list " << endl;

        return;
    }
    if (position == 1)
    {
        Node *temp = head;

        /*Updating Head*/
        head = temp->next;

        temp->next = NULL;

        delete temp;
        return;
    }
    if (position == lenghtofLinkList(head))
    {
        Node *previous = NULL;
        Node *current = head;
        int pos = 1;

        while (pos < position)
        {
            previous = current;
            current = current->next;

            pos++;
        }

        previous->next = current->next;
        tail = previous ;

        delete current;

        return;
    }
    /*For Node 2 to end*/
    Node *previous = NULL;
    Node *current = head;
    int pos = 1;

    while (pos < position)
    {
        previous = current;
        current = current->next;

        pos++;
    }

    previous->next = current->next;

    delete current;
}

// ============================================================================ //
// ==============Print Link List=============================================== //
// ============================================================================ //

void printLinkList(Node *&head)
{
    Node *temp = head;
    lenghtofLinkList(head);
    cout << " Lenght : " << lenghtofLinkList(head) << " - Link List : [<-   ";
    while (temp != NULL)
    {
        cout << temp->data << "   ";

        temp = temp->next;
    }
    cout << "->]" << endl;
}

// ============================================================================ //
// ============================================================================ //
// ==============Mian Function================================================= //
// ============================================================================ //
// ============================================================================ //

int main()
{
    Node* head1 = NULL ;
    Node* head2 = NULL ;
    Node*tail1 = NULL ;
    
}