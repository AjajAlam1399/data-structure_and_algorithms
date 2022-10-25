#include <bits/stdc++.h>
using namespace std;

int globalspace = 10;

class node
{
public:
    node *left;
    node *right;
    int data;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    node *insert_recursively(node *root, node *newnode)
    {
        if (root == NULL)
        {
            root = newnode;
            return root;
        }
        else if (root->data > newnode->data)
        {
            root->left = insert_recursively(root->left, newnode);
        }
        else if (root->data < newnode->data)
        {
            root->right = insert_recursively(root->right, newnode);
        }
        else
        {
            return root;
        }
        return root;
    }
    void display(node *root, int space)
    {
        if (root == NULL)
        {
            return;
        }
        space += globalspace;
        display(root->right, space);
        for (int i = globalspace; i < space; i++)
        {
            cout << " ";
        }
        cout << root->data << endl;
        display(root->left, space);
    }

    vector<int> inorder(node *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        stack<node *> st;

        node *temp = root;

        while (true)
        {
            if (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                if (st.empty())
                    break;
                temp=st.top();
                result.push_back(temp->data);
                st.pop();
                temp = temp->right;
            }
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BST t;
    int n;
    cin >> n;
    node *newroot = NULL;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        node *newnode = new node(num);
        t.root = t.insert_recursively(t.root, newnode);
    }
    vector<int> inorder = t.inorder(t.root);

    for (auto it : inorder)
        cout << it << " ";
}