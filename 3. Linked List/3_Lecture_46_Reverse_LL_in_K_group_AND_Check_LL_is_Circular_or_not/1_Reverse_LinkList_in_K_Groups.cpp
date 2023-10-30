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
        tail = previous;

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
// ==============Reverse Link List in K Groups================================= //
// ============================================================================ //

Node *reverseLinkList_In_K_Group(Node *&head, int k)
{
    // Base Case
    if (head == NULL)
    {
        return NULL;
    }

    // Code
    Node *before = NULL;
    Node *current = head;
    Node *temp = NULL;

    int i = 0;
    while (current != NULL && i < k)
    {
        temp = current->next;
        current->next = before;
        before = current;
        current = temp;

        i++;
    }

    if (current != NULL)
    {
        head->next = reverseLinkList_In_K_Group(current, k);
    }

    return before;
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
    // Creting pointer for head ;
    Node *head = NULL;
    Node *tail = NULL;
    printLinkList(head);
    // Creating first Node and assign the address to *head pointer
    head = new Node(10);
    tail = head;

    insertAtHead(head, 20);
    printLinkList(head);

    insertAtHead(head, 30);
    printLinkList(head);

    insertAtHead(head, 40);
    printLinkList(head);

    insertAtHead(tail, 50);
    printLinkList(head);

    insertAtHead(tail, 60);
    printLinkList(head);

    insertAtHead(tail, 70);
    printLinkList(head);

    insertAtHead(head, 80);
    printLinkList(head);

    insertAtHead(head, 90);
    printLinkList(head);

    Node *pre = NULL;
    Node *reverseList = reverseLinkList_In_K_Group(head, 4);
    printLinkList(reverseList);
}