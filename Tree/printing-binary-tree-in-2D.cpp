#include <iostream>
using namespace std;

int globalspace = 5;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
            return false;
    }

    void insertNode(TreeNode *newnode)
    {

        if (isEmpty())
        {
            root = newnode;
            cout << "node inseted at the root !" << endl;
            return;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (temp->data == newnode->data)
                {
                    cout << "duplicate is not allowed please try with the diffrent node" << endl;
                    break;
                }
                else if (temp->data > newnode->data && temp->left == NULL)
                {
                    temp->left = newnode;
                    cout << "node inserted as left child" << endl;
                    break;
                }
                else if (temp->data > newnode->data)
                {
                    temp = temp->left;
                }
                else if (temp->data < newnode->data && temp->right == NULL)
                {
                    temp->right = newnode;
                    cout << "node inserted as right child !" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += globalspace;
        print2D(r->right, space);
        cout << endl;
        for (int i = globalspace; i < space; i++)
        {
            cout << " ";
        }
        cout << r->data << endl;
        print2D(r->left, space);
    }
};

int main()
{
    BST T1;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        TreeNode *n = new TreeNode(num);
        T1.insertNode(n);
    }
    T1.print2D(T1.root, 5);
}