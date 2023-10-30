#include <iostream>
#include <time.h>  // for timr
#include <cstdlib> //for srand() and rand()
#include <queue>   //for printing tree

using namespace std;


// - NODE CLASSS -
// - NODE CLASSS -
class Node
{
public:
    Node *left;
    int data;
    Node *right;

    // - CONSTRUCTOR -
    Node(int value)
    {
        left = NULL;
        data = value;
        right = NULL;
    }
};

// - FUNCTION() ADD NODE IN AVL TREE BINARY -
// - FUNCTION() ADD NODE IN AVL TREE BINARY -
void addInBinaryAvlTree(Node *&root, int data)
{
    // BASE CASE
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }

    // LAKIN AGAR ASA NHI HA
    srand(time(0)); 
    int val = ((rand()) % 2);    

    if (val == 1)
    {
        addInBinaryAvlTree(root->left, data);
    }
    else
    {
        addInBinaryAvlTree(root->right, data);
    }
}

// - Create Simple Avl Tree -
// - Create Simple Avl Tree -
void createSimpleAVLTree(Node *&root)
{
    cout << "Enter how many Values you want to ADD : ";
    int num;
    cin >> num;
    cout << endl;

    int value;
    for (auto i = 0; i < num; i++)
    {
        cout << "Enter value : ";
        cin >> value;

        addInBinaryAvlTree(root, value);
    }
}

// - Print Tree -
// - Print Tree -
void printTree(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree Empty ..." << endl;
        return;
    }

    cout << endl
         << "   - Tree - " << endl
         << endl;

    queue<Node *> quee;
    Node *temp;
    quee.push(root);
    quee.push(NULL);
    

    while (!quee.empty())
    {
        temp = quee.front();
        quee.pop();

        // AGAR VALUE NULL HA
        if (temp == NULL)
        {
            cout << endl;
            if (!quee.empty())
            {
                quee.push(NULL);
            }
        }
        // AGAR VALUE NULL NHI HA
        else
        {
            cout << temp->data << "  ";

            // AGAR LEFT NULL NHI HA
            if (temp->left != NULL)
            {
                quee.push(temp->left);
            }
            // AGAR RIGHT NULL NHI HA
            if (temp->right != NULL)
            {
                quee.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;

    // Test Input
    // 14 14 13 12 11 10 9 8 7 6 5 4 3 2 1
    createSimpleAVLTree(root);

    cout << endl;

    printTree(root);
}