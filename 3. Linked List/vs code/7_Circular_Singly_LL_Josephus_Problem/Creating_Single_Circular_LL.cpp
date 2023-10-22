#include <iostream>

using namespace std;

/*  Circular Link list Class  */
template <typename T>
class CircularLL
{
    /*===Node Class===*/
    class Node
    {
    public:
        T data;
        Node *next;

        /*Constructor*/
        Node(int d)
        {
            data = d;
            next = this;
        }
    };

    Node *head;
    Node *tail;
    int sizeofCLL;

public:
    /*Constructor*/
    CircularLL()
    {
        head = NULL;
        tail = NULL;
        sizeofCLL = 0;
    }

    int size()
    {
        return sizeofCLL;
    }

    void push_front(T value)
    {
        Node *newnode = new Node(value);
        sizeofCLL++;
        // Agar koi node ha he nhi
        if (head == NULL)
        {
            head = tail = newnode;

            return;
        }

        // Agar LL ma ak be node ha
        newnode->next = head;
        tail->next = newnode;

        head = newnode;
    }

    void push_back(T value)
    {
        Node *newnode = new Node(value);
        sizeofCLL++;
        // agar koi node nhi ha
        if (head ==  NULL)
        {
            head = tail = newnode;

            return;
        }

        // Agar LL ma ak be node ha
        Node *hold = tail->next;

        tail->next = newnode;
        newnode->next = hold;
        tail = newnode;
    }
    
    void pop_fornt()
    {
        // agar koi node nhi ha
        if(head == NULL)
        {
            return;
        }

        sizeofCLL--;
        //Agar Srif ak node ha 
        if(head == tail)
        {
            delete head;
            head = tail = NULL ;

            return ;
        }

        //Agar ak sa zada node ha 
        Node* hold = head;
        head = head -> next ;
        tail->next = head ;

        delete hold;
    }

    void pop_back()
    {
        // agar koi node nhi ha
        if(head == NULL)
        {
            return;
        }

        sizeofCLL--;
        //Agar Srif ak node ha 
        if(tail == head)
        {
            delete tail;
            head = tail = NULL ;

            return ;
        }

        //Agar ak sa zada node ha
        Node* temp = head ;

        while (((temp -> next) -> next) != head)
        {
            temp = temp ->next ;
        }

        Node* hold = temp->next ;

        temp ->next = ((temp -> next) -> next);
        tail = temp ;

        delete hold;
    }

    void print()
    {
        // agar koi node nhi ha
        if (head == NULL)
        {
            cout << "Empty List..." << endl ; 
            return;
        }

         // Agar LL ma ak be node ha
        Node *temp = head;
        cout << "List :  " ;
        do
        {
            cout << temp->data << " --> " ;
            temp = temp->next;
        }
        while (temp != head) ;
        cout << endl ;
    }
};

int main()
{
    CircularLL <int> obj;
    
    // cout << "Size : " << obj.size() << endl;
    // obj.print();
    obj.push_front(10);
    // cout << "Size : " << obj.size() << endl;
    // obj.print();
    obj.push_back(20);
    // cout << "Size : " << obj.size() << endl;
    // obj.print();
    obj.push_front(5);
    // cout << "Size : " << obj.size() << endl;
    // obj.print();
    obj.push_back(25);
    // cout << "Size : " << obj.size() << endl;
    // obj.print();
    obj.push_front(0);
    // cout << "Size : " << obj.size() << endl;
    // obj.print();
    obj.push_back(30);
    cout << "Size : " << obj.size() << endl;
    obj.print();
    
    obj.pop_fornt();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_back();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_fornt();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_back();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_fornt();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_back();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_fornt();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_fornt();
    cout << "Size : " << obj.size() << endl;
    obj.print();

    obj.pop_back();
    cout << "Size : " << obj.size() << endl;
    obj.print();
}