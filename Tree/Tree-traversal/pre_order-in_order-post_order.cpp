#include <bits/stdc++.h>
using namespace std;

// time complexity (O(n))

// space complexity (O(n))

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
    void traversal(node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
    {
        if (root == NULL)
        {
            return;
        }
        stack<pair<node *, int>> st;
        st.push(make_pair(root, 1));
        while (!st.empty())
        {
            auto it = st.top();
            int num = it.second;
            st.pop();
            if (num == 1)
            {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->left != NULL)
                {
                    st.push(make_pair(it.first->left, 1));
                }
            }
            else if (num == 2)
            {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->right != NULL)
                {
                    st.push(make_pair(it.first->right, 1));
                }
            }
            else
            {
                post.push_back(it.first->data);
            }
        }
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
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    t.traversal(t.root, preorder, inorder, postorder);
    for (auto it : preorder)
        cout << it << " ";
    cout << endl;
    for (auto it : inorder)
        cout << it << " ";
    cout << endl;
    for (auto it : postorder)
        cout << it << " ";
    cout << endl;
}