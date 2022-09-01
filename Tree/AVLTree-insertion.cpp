#include <iostream>
using namespace std;

int globslspace = 5;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        data = 0;
        left = right = NULL;
    }
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class AVLBST
{
public:
    TreeNode *root;

    AVLBST()
    {
        root = NULL;
    }

    int TreeHeight(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        int lheight = TreeHeight(r->left);
        int rheight = TreeHeight(r->right);
        if (lheight > rheight)
        {
            return lheight + 1;
        }
        else
            return rheight + 1;
    }

    int BalanceFactor(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        return ((TreeHeight(r->left)) - (TreeHeight(r->right)));
    }

    TreeNode *rightRotate(TreeNode *y)
    {

        TreeNode *x = y->left;
        TreeNode *t = x->right;
        x->right = y;
        y->left = t;
        return x;
    }

    TreeNode *leftRotate(TreeNode *y)
    {
        TreeNode *x = y->right;
        TreeNode *t = x->left;
        x->left = y;
        y->right = t;
        return x;
    }

    TreeNode *insertNode(TreeNode *r, TreeNode *newnode)
    {
        if (r == NULL)
        {
            r = newnode;
            return r;
        }
        else if (r->data > newnode->data)
        {
            r->left = insertNode(r->left, newnode);
        }
        else if (r->data < newnode->data)
        {
            r->right = insertNode(r->right, newnode);
        }
        else
        {
            cout << "Duplicate is not allowed " << endl;
            return r;
        }
        int bf = BalanceFactor(r);
        if (bf > 1 && r->left->data > newnode->data)
        {

            return rightRotate(r);
        }
        if (bf < -1 && r->right->data < newnode->data)
        {
            return leftRotate(r);
        }
        if (bf > 1 and r->left->data < newnode->data)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        if (bf < -1 && r->right->data < newnode->data)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += globslspace;
        print2D(r->right, space);
        cout << endl;
        for (int i = globslspace; i < space; i++)
        {
            cout << " ";
        }
        cout << r->data << endl;
        print2D(r->left, space);
    }
};

int main()
{
    AVLBST T1;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        TreeNode *n = new TreeNode(num);
        T1.root = T1.insertNode(T1.root, n);
    }
    T1.print2D(T1.root, 5);
}