
// For Circular Double ;

// #include <iostream>

// using namespace std;

// class Node
// {
// public:
//     Node *previous;
//     int data;
//     Node *next;

//     // cons
//     Node(int num)
//     {
//         this->previous = this;
//         this->data = num;
//         this->next = this;
//     }
// };

// // ================================================================ //
// // ==================Insert in linklist============================ //
// // ================================================================ //

// void insertNode(Node *&tail, int searchData /*jas ka aga node insert karne ha*/, int data /*to put in new node*/)
// {
//     // cout << "1" << endl ;
//     if (tail == NULL) /*koi node ha he nhi*/
//     {
//         // cout << "--1" << endl ;
//         tail = new Node(data);
//         return;
//     }
//     else
//     {
//         Node *temp = tail;

//         bool status = false;
//         do
//         {
//             if (temp->data == searchData)
//             {
//                 status = true;
//                 break;
//             }
//             temp = temp->next;
//         } while (temp != tail);

//         if (status == false)
//         {
//             cout << "Wrong Data in put (No Node have " << data << " date ) " << endl;
//             return;
//         }
//         else
//         {
//             Node *insertedNode = new Node(data);

//             insertedNode->next = temp->next;
//             insertedNode->previous = temp;

//             temp->next = insertedNode;
//             (insertedNode->next)->previous = insertedNode;
//         }
//     }
// }

// // ================================================================ //
// // ==================Delete in linklist============================ //
// // ================================================================ //

// void deleteNode(Node *tail, int deletevalue)
// {
//     if (tail == NULL) /*koi node ha he nhi*/
//     {
//         cout << " Cannot delete ( Empty Link List ) " << endl;
//         return;
//     }
//     else
//     {
//         Node *temp = tail;

//         bool status = false;
//         do
//         {
//             if (temp->data == deletevalue)
//             {
//                 status = true;
//                 break;
//             }
//             temp = temp->next;
//         } while (temp != tail);

//         if (status == false)
//         {
//             cout << "Wrong Data in put (No Node have " << deletevalue << " date ) " << endl;
//             return;
//         }
//         else
//         {
//             (temp->previous)->next = temp->next;
//             (temp->next)->previous = temp->previous;

//             temp->next = NULL;
//             temp->previous = NULL;

//             delete temp;
//         }
//     }
// }

// // ================================================================ //
// // ==================Check Circular LinkList======================= //
// // ================================================================ //

// bool checkcircular(Node *&head)
// {
//     if (head == NULL)
//     {
//         return 0;
//     }

//     Node *temp = head->next;

//     while (temp != NULL && temp != head)
//     {
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         return 0;
//     }
//     if (temp == head)
//     {
//         return 1;
//     }
// }

// // ================================================================ //
// // ==================Print LinkList================================ //
// // ================================================================ //

// void printlinklist(Node *&tail)
// {
//     Node *temp = tail;

//     if (temp == NULL)
//     {
//         cout << "Link List is Empty " << endl;
//         return;
//     }
//     cout << " [~   ";
//     do
//     {
//         cout << temp->data << "   ";
//         temp = temp->next;
//     } while (temp != tail);
//     cout << "~]" << endl;
// }

// // ================================================================ //
// // ==================Main Function================================= //
// // ================================================================ //

// int main()
// {
//     Node *tail = NULL;
//     // cout << tail << endl ;
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     insertNode(tail, 10, 10);
//     // cout << tail << endl ;
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     insertNode(tail, 10, 20);
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     insertNode(tail, 10, 15);
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     insertNode(tail, 20, 25);
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     insertNode(tail, 25, 30);
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     deleteNode(tail, 15);
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;

//     deleteNode(tail, 25);
//     printlinklist(tail);
//     cout << "Circular Status : " << checkcircular(tail) << endl
//          << endl;
// }

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
// ==============check circular Link List=============================================== //
// ============================================================================ //

bool checkcircular(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return 0;
    }
    if (temp == head)
    {
        return 1;
    }
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
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    // Creating first Node and assign the address to *head pointer
    head = new Node(10);
    tail = head;

    insertAtHead(head, 20);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    insertAtHead(head, 30);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    insertAtHead(head, 40);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    // Insert at tail
    insertAtTail(tail, 20);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    insertAtTail(tail, 30);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    insertAtTail(tail, 40);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    // Intert at any position;
    // Intert at any position;

    /*Insert at first*/
    insertAtAnyPostion(head, tail, 1, 90);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    /*Insert at Last*/
    insertAtAnyPostion(head, tail, lenghtofLinkList(head) + 1, 90);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    /*Insert in between*/
    insertAtAnyPostion(head, tail, 5, 0);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    insertAtAnyPostion(head, tail, 5, 10);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    // Delete any Postion
    // Delete any Postion

    /*Delete First*/
    DeleteAnyPostion(head, tail, 1);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    /*Delete lAST*/
    DeleteAnyPostion(head, tail, lenghtofLinkList(head));
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;

    /*Delete In b/w*/
    DeleteAnyPostion(head, tail, 5);
    printLinkList(head);
    cout << "Circular Status : " << checkcircular(head) << endl
         << endl;
}