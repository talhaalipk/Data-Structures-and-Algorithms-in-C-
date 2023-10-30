
#include <iostream>

using namespace std;

// =========================== //
// ======Create Node Class==== //
// =========================== //
class Node
{
public:
    // Data Members
    Node *pervious;
    int data;
    Node *next;

    // Constructor
    Node(int num)
    {
        this->pervious = NULL;
        this->data = num;
        this->next = NULL;
    }
};

// =========================== //
// ======Lenght of Link List== //
// =========================== //

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

// =========================== //
// ======Insert At Head======= //
// =========================== //

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    temp->next = head;

    // phala  head
    head->pervious = temp;

    head = temp;
}

// =========================== //
// ======Insert At Tail======= //
// =========================== //

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    temp->pervious = tail;

    tail = temp;
}

// =========================== //
// ======Insert At Any Postion //
// =========================== //

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
    insertNode->pervious = temp;
    temp->next = insertNode;
    (temp->next)->pervious = insertNode;
}

// =========================== //
// ======Delate Any Postion=== //
// =========================== //

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

        temp->next->pervious = NULL;

        /*Updating Head*/
        head = temp->next;

        temp->next = NULL;

        delete temp;
        return;
    }
    if (position == lenghtofLinkList(head))
    {
        Node *current = head;
        int pos = 1;

        while (pos < position)
        {
            current = current->next;

            pos++;
        }

        (current->pervious)->next = NULL;

        tail = current->pervious;

        current->pervious = NULL;
        current->next = NULL;
        delete current;

        return;
    }
    /*For Node 2 to end*/
    Node *current = head;
    int pos = 1;

    while (pos < position)
    {
        current = current->next;

        pos++;
    }

    (current->pervious)->next = current->next;
    (current->next)->pervious = current->pervious;

    delete current;

    return;
}

// =========================== //
// ======Print Link List====== //
// =========================== //

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

// =========================== //
// =========================== //
// ======Mian Function======== //
// =========================== //
// =========================== //

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

    // Insert at tail
    insertAtTail(tail, 20);
    printLinkList(head);

    insertAtTail(tail, 30);
    printLinkList(head);

    insertAtTail(tail, 40);
    printLinkList(head);

    // Intert at any position;
    // Intert at any position;

    /*Insert at first*/
    insertAtAnyPostion(head, tail, 1, 90);
    printLinkList(head);

    /*Insert at Last*/
    insertAtAnyPostion(head, tail, lenghtofLinkList(head) + 1, 90);
    printLinkList(head);

    /*Insert in between*/
    insertAtAnyPostion(head, tail, 5, 0);
    printLinkList(head);

    insertAtAnyPostion(head, tail, 5, 10);
    printLinkList(head);

    // Delete any Postion
    // Delete any Postion

    /*Delete First*/
    DeleteAnyPostion(head, tail, 1);
    printLinkList(head);

    /*Delete lAST*/
    DeleteAnyPostion(head, tail, lenghtofLinkList(head));
    printLinkList(head);

    /*Delete In b/w*/
    // cout << "Head : " << head-> data << endl ;
    // cout << "Tail : " << tail->pervious -> data << endl ;
    // cout << "5 data and address " << head->next->next->next->next << " : " << head->next->next->next->next->data << endl;
    DeleteAnyPostion(head, tail, 5);
    printLinkList(head);
    // cout << "5 data and address " << head->next->next->next->next << " : " << head->next->next->next->next->data << endl;

}

