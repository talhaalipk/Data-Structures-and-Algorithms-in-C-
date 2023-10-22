
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
// ===insert In Sorted List=== //
// =========================== //

void insertNode_inSortendlist(Node *&head, Node *&tail, int value)
{
    Node *temp = head;

    // AGAR Value 1 Par ane ho
    if (value < temp->data)
    {
        insertAtHead(head, value);
        return;
    }

    int count = 1;
    while (temp != NULL && !(value < temp->data))
    {
        count++;
        temp = temp->next;
    }

    // AGAR KOI BE VALUE US SA zada nhi ha
    if (temp == NULL)
    {
        insertAtTail(tail, value);
        return;
    }

    // Ager koi darman ma ha
    insertAtAnyPostion(head, tail, count, value);
    return;
}

// =========================== //
// ======Mian Function======== //
// =========================== //

int main()
{
    // Creting pointer for head ;
    Node *head = NULL;
    Node *tail = NULL;
    printLinkList(head);
    // Creating first Node and assign the address to *head pointer
    head = new Node(90);
    tail = head;

    insertAtHead(head, 60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 10);
    printLinkList(head);

    insertNode_inSortendlist(head,tail,15);
    insertNode_inSortendlist(head,tail,35);
    insertNode_inSortendlist(head,tail,45);
    insertNode_inSortendlist(head,tail,55);
    insertNode_inSortendlist(head,tail,70);
    insertNode_inSortendlist(head,tail,520);
    printLinkList(head);
}
