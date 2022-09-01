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
    TreeNode *InsertRecurcive(TreeNode *r, TreeNode *newnode)
    {
        if (r == NULL)
        {
            r = newnode;
            return r;
        }
        else if (r->data > newnode->data)
        {
            r->left = InsertRecurcive(r->left, newnode);
        }
        else if (r->data < newnode->data)
        {
            r->right = InsertRecurcive(r->right, newnode);
        }
        else
        {
            cout << "Duplicate is not allowed " << endl;
            return r;
        }
        return r;
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
        T1.root = T1.InsertRecurcive(T1.root, n);
    }
    T1.print2D(T1.root, 5);
}