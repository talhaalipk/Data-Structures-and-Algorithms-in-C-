#include <iostream>
#include <queue> //for printing tree

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
void addInBinarySearchTree(Node *&root, int data)
{
    // BASE CASE
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }

    // - AGAR ROOT NULL NHI HA  -
    if (data < root->data)
    {
        addInBinarySearchTree(root->left, data);
    }
    else
    {
        addInBinarySearchTree(root->right, data);
    }
}

// - Create Simple Avl Tree -
// - Create Simple Avl Tree -
void createSimpleSearchTree(Node *&root)
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

        addInBinarySearchTree(root, value);
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

void inOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    Node *root = NULL;

    // Test Input
    // 10 90 27 56 98 75 23 21 1 8 9 
    createSimpleSearchTree(root);
    cout << endl;

    printTree(root);

    cout << endl << "   - Inorder -" << endl <<endl ;
    inOrderTraversal(root);
}