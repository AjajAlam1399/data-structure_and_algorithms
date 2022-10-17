#include <bits/stdc++.h>
using namespace std;
#define Globalspace 5
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};

class BST
{

public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void insertion(Node *newnode)
    {
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == newnode->data)
            {
                cout << "Duplicate is not allowed !" << endl;
                return;
            }
            else if (newnode->data < temp->data && temp->left == NULL)
            {
                temp->left = newnode;
                break;
            }
            else if (newnode->data < temp->data)
            {
                temp = temp->left;
            }
            else if (newnode->data > temp->data && temp->right == NULL)
            {
                temp->right = newnode;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    void print2D(Node *root, int space)
    {
        if (root == NULL)
        {
            return;
        }
        space = space + Globalspace;
        print2D(root->right, space);
        cout << endl;
        for (int i = Globalspace; i < space; i++)
        {
            cout << " ";
        }
        cout << root->data << endl;
        print2D(root->left, space);
    }
};

int main(){

    BST t;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        Node* newnode=new Node(data);
        t.insertion(newnode);
    }
    t.print2D(t.root,10);
}