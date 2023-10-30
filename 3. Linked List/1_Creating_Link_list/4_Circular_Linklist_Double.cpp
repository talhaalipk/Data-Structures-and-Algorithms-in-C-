#include <iostream>

using namespace std;

class Node
{
public:
    Node *previous;
    int data;
    Node *next;

    // cons
    Node(int num)
    {
        this->previous = this;
        this->data = num;
        this->next = this;
    }
};

// ================================================================ //
// ==================Insert in linklist============================ //
// ================================================================ //

void insertNode(Node *&tail, int searchData /*jas ka aga node insert karne ha*/, int data /*to put in new node*/)
{
    // cout << "1" << endl ;
    if (tail == NULL) /*koi node ha he nhi*/
    {
        // cout << "--1" << endl ;
        tail = new Node(data);
        return;
    }
    else
    {
        Node *temp = tail;

        bool status = false;
        do
        {
            if (temp->data == searchData)
            {
                status = true;
                break;
            }
            temp = temp->next;
        } while (temp != tail);

        if (status == false)
        {
            cout << "Wrong Data in put (No Node have " << data << " date ) " << endl;
            return;
        }
        else
        {
            Node *insertedNode = new Node(data);

            insertedNode->next = temp->next;
            insertedNode->previous = temp;

            temp->next = insertedNode;
            (insertedNode->next)->previous = insertedNode;
        }
    }
}

// ================================================================ //
// ==================Delete in linklist============================ //
// ================================================================ //

void deleteNode(Node *tail, int deletevalue)
{
    if (tail == NULL) /*koi node ha he nhi*/
    {
        cout << " Cannot delete ( Empty Link List ) " << endl;
        return;
    }
    else
    {
        Node *temp = tail;

        bool status = false;
        do
        {
            if (temp->data == deletevalue)
            {
                status = true;
                break;
            }
            temp = temp->next;
        } while (temp != tail);

        if (status == false)
        {
            cout << "Wrong Data in put (No Node have " << deletevalue << " date ) " << endl;
            return;
        }
        else
        {
            (temp->previous)->next = temp->next;
            (temp->next)->previous = temp->previous ;

            temp->next = NULL;
            temp->previous = NULL;

            delete temp ;
        }
    }
}

// ================================================================ //
// ==================Print LinkList================================ //
// ================================================================ //

void printlinklist(Node *&tail)
{
    Node *temp = tail;

    if (temp == NULL)
    {
        cout << "Link List is Empty " << endl;
        return;
    }
    cout << " [~   ";
    do
    {
        cout << temp->data << "   ";
        temp = temp->next;
    } while (temp != tail);
    cout << "~]" << endl;
}

// ================================================================ //
// ==================Main Function================================= //
// ================================================================ //

int main()
{
    Node *tail = NULL;
    // cout << tail << endl ;
    printlinklist(tail);

    insertNode(tail, 10, 10);
    // cout << tail << endl ;
    printlinklist(tail);

    insertNode(tail, 10, 20);
    printlinklist(tail);

    insertNode(tail, 10, 15);
    printlinklist(tail);

    insertNode(tail, 20, 25);
    printlinklist(tail);

    insertNode(tail, 25, 30);
    printlinklist(tail);

    deleteNode(tail,15);
    printlinklist(tail);

    deleteNode(tail,25);
    printlinklist(tail);
}