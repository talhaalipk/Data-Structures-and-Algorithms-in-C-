#include <iostream>
#include <queue>

using namespace std;

/*-------------------------------------------------*/
/*-------------Node Creation-----------------------*/
/*-------------------------------------------------*/
class Node
{
public:
    Node *left;
    int data;
    Node *right;

    // constructor
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


/*-------------------------------------------------*/
/*-------------Function for Creating Tree----------*/
/*-------------------------------------------------*/
Node *creatingBinaryTree(Node *root)
{
    cout << "Enter Data  " << endl ;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter Data it the left of " << data << " --> " << endl;
    root->left = creatingBinaryTree(root->left);

    cout << "Enter Data it the right of " << data << " --> " << endl;
    root->right = creatingBinaryTree(root->right);

    return root;
}

/*-------------------------------------------------*/
/*-------Function for Level Order Traversal--------*/
/*-------------------------------------------------*/
void binaryTreelevelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data
                 << "  ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


/*-------------------------------------------------*/
/*-------Function for Pre-Order Traversal----------*/
/*-------------------------------------------------*/
void preoderTraversal(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    cout << root->data << " " ;
    preoderTraversal(root->left);
    preoderTraversal(root->right);

}

/*-------------------------------------------------*/
/*-------Function for In-Order Traversal----------*/
/*-------------------------------------------------*/
void inoderTraversal(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    inoderTraversal(root->left);
    cout << root->data << " ";
    inoderTraversal(root->right);

}

/*-------------------------------------------------*/
/*-------Function for Post-Order Traversal----------*/
/*-------------------------------------------------*/
void postoderTraversal(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    postoderTraversal(root->left);
    postoderTraversal(root->right);
    cout << root->data << " ";

}

int main()
{
    Node *root = NULL;

    //----------Test Values-----------//
    // 2 4 8 -1 -1 -1 6 -1 -1
    // 1 2 4 7 -1 -1 8 -1 -1 5 -1 9 -1 -1 3 -1 9 7 -1 -1 -1
    root = creatingBinaryTree(root);

    binaryTreelevelOrderTraversal(root);
    cout << endl ;
    cout << "Pre Order : " << endl ;
    preoderTraversal(root);
    cout << endl ;
    cout << "In Order : " << endl ;
    inoderTraversal(root);
    cout << endl ;
    cout << "Post Order : " << endl ;
    postoderTraversal(root);
}