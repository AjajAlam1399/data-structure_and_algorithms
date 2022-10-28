#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int globalspace = 10;

class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }

    void insert(node *&root, node *newnode)
    {
        if (root == NULL)
        {
            root = newnode;
            cout << "inert at root" << endl;
            return;
        }
        node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == newnode->data)
            {
                cout << "duplicate is not allowed" << endl;
                return;
            }
            else if (temp->data > newnode->data && temp->left == NULL)
            {
                temp->left = newnode;
                cout << "insert at left" << endl;
                return;
            }
            else if (temp->data > newnode->data)
            {
                temp = temp->left;
            }
            else if (temp->data < newnode->data && temp->right == NULL)
            {
                temp->right = newnode;
                cout << "insert at the right" << endl;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    void display(node *root, int space)
    {
        if (root == NULL)
        {
            return;
        }
        space = space + globalspace;
        display(root->right, space);
        for (int i = globalspace; i < space; i++)
        {
            cout << " ";
        }
        cout << root->data << endl;
        display(root->left, space);
    }

    vector<int> postorder(node *root)
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }
        stack<node *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left){
                st1.push(root->left);
            }
            if(root->right){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            result.push_back(st2.top()->data);
            st2.pop();
        }
        return result;
    }
};
int main()
{
    BST t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        node *newnode = new node(num);
        t.insert(t.root, newnode);
    }
    // t.display(t.root, 5);
    vector<int> preoreder = t.postorder(t.root);
    for (auto i : preoreder)
        cout << i << " ";
}