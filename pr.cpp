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
    void pre_order(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data << " ";
        pre_order(r->left);
        pre_order(r->right);
    }
    void in_order(node* r){
        if(r==NULL){
            return;
        }
        in_order(r->left);
        cout<<r->data<<" ";
        in_order(r->right);
    }
    void post_order(node* r){
        if(r==NULL){
            return ;
        }
        post_order(r->left);
        post_order(r->right);
        cout<<r->data<<" ";
    }
    bool search(node* r,int val){
        if(r==NULL){
            return false;
        }
        node* temp=r;
        while(temp!=NULL){
            if(temp->data==val){
                return true;
            }
            else if(temp->data>val){
                temp=temp->left;
            }
            else if(temp->data<val){
                temp=temp->right;
            }
        }
        return false;
    }
    int height(node* root){
        if(root==NULL){
            return -1;
        }
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight){
            return lheight+1;
        }
        else{
            return rheight+1;
        }
    }
    void print_BFS(node* root,int levle){
        if(root==NULL){
            return;
        }
        if(levle==0){
            cout<<root->data<<" ";
        }
        print_BFS(root->left,levle-1);
        print_BFS(root->right,levle-1);
    }
    void BFS(node* root){
        int h=height(root);

        for(int i=0;i<=h;i++){
            print_BFS(root,i);
        }
    }
    node* minVal(node* r){
        node* temp=r;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    node* delete_node(node* root,int val){
        if(root==NULL){
            return root;
        }
       else if(root->data>val){
            root->left=delete_node(root->left,val);
        }
        else if(root->data<val){
            root->right=delete_node(root->right,val);
        }
        else{
            if(root->left==NULL){
                node* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                node* temp=root->left;
                delete root;
                return temp;
            }
            else{
                node* temp=minVal(root->right);
                root->data=temp->data;
                root->right=delete_node(root->right,temp->data);
            }
        }
        return root;
    }
};
int main()
{
    // #ifndef ONLINE_JUGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
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
    t.root=t.delete_node(t.root,45 );
    t.BFS(t.root);
}