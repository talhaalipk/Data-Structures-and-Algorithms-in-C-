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
void createBinarySearchTree(Node *&root)
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

// - Search-value in BST -
// - Search-value in BST -
bool searchInBST(Node *root, int searchValue)
{
    Node *temp = root;
    bool returnValue = false;

    while (temp != NULL)
    {
        // AGAR MAL GYE
        if (temp->data == searchValue)
        {
            returnValue = true;
            break;
        }

        if (searchValue < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return returnValue;
}

// - Get Min in BST -
// - Get Min in BST -
Node *getMinInBST(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// - Get Max in BST -
// - Get Max in BST -
Node *getMaxInBST(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

// - Delection in BST -
// - Delection in BST -
Node *deleteInBST(Node *root, int del_value)
{
    // Agar nhi male
    if (root == NULL)
    {
        return root;
    }

    // Agar delete wale node pa aa gye ha
    else if (root->data == del_value)
    {
        // 0 child
        // Agar koi child nhi ha leaf node ha
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child AK child

        // left childe ha
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child ha
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // ASAL masla
        //  2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = getMinInBST(root->right) -> data;
            root->data = min;

            root-> right = deleteInBST(root->right, min);
            return root;
        }
    }

    else if (del_value < root->data)
    {
        root->left = deleteInBST(root->left, del_value);
    }
    else
    {
        root->right = deleteInBST(root->right, del_value);
    }

    return root;
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

// - In-order Treversal -
// - In-order Treversal -
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
    createBinarySearchTree(root);
    cout << endl;

    cout << "   - Inorder -" << endl;
    inOrderTraversal(root);

    int search = 90;

    // cout << endl
    //      << "Searching " << search << " BST Bool return : " << searchInBST(root, search) << endl;

    cout << endl << endl
         << "deleting value =  " << search << endl;

    root = deleteInBST(root,search);

    cout << endl
         << "   - Inorder -" << endl;
    inOrderTraversal(root);
}