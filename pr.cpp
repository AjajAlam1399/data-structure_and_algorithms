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

    vector<int> preorder(node *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        stack<node *> s;
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            result.push_back(root->data);
            if (root->right != NULL)
            {
                s.push(root->right);
            }
            if (root->left != NULL)
            {
                s.push(root->left);
            }
        }
        return result;
    }
};

void traversal(node* root,vector<int>preorder,vector<int>&inorder,vector<int>&postorder){
    node* temp=root;

    stack<pair<node*,int>>st;

    st.push({temp,0});

    while(!st.empty()){
        temp=st.top().first;
        int l=st.top().second;
        st.pop();
        
        if(l==0){
            preorder.push_back(temp->data);
            st.push({temp,l+1});
            if(temp->left){
                st.push({temp->left,0});
            }
        }
        else if(l==1){
            inorder.push_back(temp->data);
            st.push({temp,l+1});
            if(temp->right){
                st.push({temp->right,0});
            }
        }
        else{
            postorder.push_back(temp->data);
        }
    }
}