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
    void preOrderTraversal(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data << " ";
        preOrderTraversal(r->left);
        preOrderTraversal(r->right);
    }
    void inorderTraversal(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        inorderTraversal(r->left);
        cout << r->data << " ";
        inorderTraversal(r->right);
    }
    void postorderTraversal(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        postorderTraversal(r->right);
        postorderTraversal(r->left);
        cout << r->data << " ";
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
    TreeNode *iterativeSearch(int val)
    {
        if (root->data == val)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;

            while (temp != NULL)
            {
                if (temp->data == val)
                {
                    return temp;
                    break;
                }
                else if (temp->data < val)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
        return NULL;
    }
    int heightOfTree(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        int lheight = heightOfTree(r->left);
        int rheight = heightOfTree(r->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }

        return -1;
    }
    void printingEachlevel(TreeNode *r, int level)
    {
        if (r == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << r->data << " ";
        }
        printingEachlevel(r->left, level - 1);
        printingEachlevel(r->right, level - 1);
    }
    void BFS(TreeNode *r)
    {
        int h = heightOfTree(r);
        for (int i = 0; i <= h; i++)
        {
            printingEachlevel(r, i);
        }
    }
    TreeNode *MinvalTreeNode(TreeNode *r)
    {
        TreeNode *temp = r;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    TreeNode *DeleteNode(TreeNode *r, int val)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->data > val)
        {
            r->left = DeleteNode(r->left, val);
        }
        else if (r->data < val)
        {
            r->right = DeleteNode(r->right, val);
        }
        else
        {
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = MinvalTreeNode(r->right);
                r->data = temp->data;
                r->right = DeleteNode(r->right, temp->data);
            }
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
        T1.insertNode(n);
    }
    T1.print2D(T1.root, 5);
    cout << endl;
    TreeNode *net = T1.DeleteNode(T1.root, 30);
    cout << net->data << endl;
    T1.print2D(net, 5);
}