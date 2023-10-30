/**
**********************************************************************************************************************************************************************************************************************************
* @file:	learning_Link_list.cpp
* @author:	Talha Ali
* @date:	2023年06月09日 19:36:06 Friday
* @brief:	https://www.youtube.com/watch?v=q8gdBn9RPeI&t=1075s
**********************************************************************************************************************************************************************************************************************************
**/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *Next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->Next = NULL;
    }
};

void InsertAtHead(Node *&Head, int data)
{
    Node* temp = new Node(data);

    temp->Next = Head;

    Head = temp;
}

void InsertAttail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->Next = temp;
    // temp->Next = NULL;

    tail = temp;
}

void InsertAtanyPosition(Node *&Head, Node*&tail, int postion, int data)
{
    // cout << "InsertAtanyPosition called " << endl;
    if (postion == 1)
    {
        InsertAtHead(Head, data);
        // cout << "InsertAtanyPosition  postion 1 called " << endl;
        return;
    }

    Node *temp = Head;
    int pos = 1;
    while (pos < postion - 1)
    {
        temp = temp->Next;
        pos++;
        // cout << "InsertAtanyPosition  loop work " << pos << endl;
    }
    // cout << "if k uper << endl ";
    cout << temp << endl; 
    if (temp->Next == NULL)
    {
        InsertAttail(tail, data);
        return;
        // cout << "InsertAtanyPosition   postion Last called " << endl;
    }
    // cout << "if k nacha << endl ";

    Node *InsertNode = new Node(data);
    // cout << "if k center << endl ";
    InsertNode->Next = temp->Next;

    temp->Next = InsertNode;
    // cout << "InsertAtanyPosition  postion Mid called " << endl;
    return;
}

void DeletePostionNode(Node *&Head, int postion)
{
    if (postion == 1)
    {
        Node *temp = Head;
        Head = Head->Next;

        delete temp;
    }
    else
    {
        Node *current = Head;
        Node *Prevous = NULL;

        int pos = 1;

        while (pos < postion )
        {
            Prevous = current;
            current = current->Next;
            pos++;
        }

        Prevous->Next = current->Next;

        delete current;
    }
}

//      Print LinkList
//      Print LinkList
void printLinkList(Node *&Head)
{
    cout << "Print Called " << endl;
    Node *temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->Next;
    }
    cout << endl;
}

int LinkListLenght(Node * &Head)
{
    Node * temp = Head ;
    
    int Lenght = 0 ;
    while (temp != NULL)
    {
        temp = temp->Next;
        Lenght++ ;
    }
    
    return Lenght;
}

int main()
{
    // /*Tail InSertion */
    // /*Tail InSertion */
    // Node *node1 = new Node(10);
    // Node *Head = node1;
    // Node *tail = node1;

    // InsertAttail(tail, 20);
    // InsertAttail(tail, 30);
    // InsertAttail(tail, 40);
    // InsertAttail(tail, 50);
    // InsertAttail(tail, 60);
    // InsertAttail(tail, 70);
    // InsertAttail(tail, 80);

    // printLinkList(Head);

    // /*Tail InSertion */
    // /*Tail InSertion
    // Node *node1 = new Node(10);
    // Node *Head = node1;
    // Node *tail = node1;


    // InsertAtHead(Head, 20);
    // InsertAtHead(Head, 30);
    // InsertAtHead(Head, 40);
    // InsertAtHead(Head, 50);

    // printLinkList(Head);       */

    // /*Position InSertion */
    // /*Position InSertion
    // InsertAtanyPosition(Head, tail, 5, 80);

    // printLinkList(Head);*/


    // /*Deleting Position InSertion */
    // /*Deleting Position InSertion
    // DeletePostionNode(Head, 5);
    // printLinkList(Head);  */

    // cout << "Lenght : " << LinkListLenght(Head) << endl ;

    Node *node1 = new Node(10.10);
    node1->Next = NULL;

    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 20.20);
    InsertAtHead(head, 30.30);

    cout << "lenght : " << LinkListLenght(head) << endl;
    printLinkList(head);

    InsertAttail(tail, 20.20);
    InsertAttail(tail, 30.30);

    cout << "lenght : " << LinkListLenght(head) << endl;
    printLinkList(head);
}
