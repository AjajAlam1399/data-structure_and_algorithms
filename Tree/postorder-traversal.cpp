#include <iostream>
using namespace std;

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
    void inorderTraversal(TreeNode* r){
        if(r=NULL){
            return;
        }
        inorderTraversal(r->left);
        cout<<r->data<<" ";
        inorderTraversal(r->right);
    }
    void postorderTraversal(TreeNode* r){
        if(r==NULL){
            return;
        }
        postorderTraversal(r->right);
        postorderTraversal(r->left);
        cout<<r->data<<" ";
    }
};

int main()
{
}