//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node *buildTree(int in[], int post[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function to return a tree created from postorder and inoreder traversals.

Node *fun(int post[], int ps, int pe, int in[], int ins, int ine)
{

    if (ps > pe || ins > ine)
    {
        return NULL;
    }

    int i;
    for (i = ins; i <= ine; i++)
    {
        if (in[i] == post[pe])
        {
            break;
        }
    }
    Node *root = new Node(post[pe]);
    int inroot = i;
    int left = inroot - ins;
    root->left = fun(post, ps, ps + left - 1, in, ins, inroot - 1);
    root->right = fun(post, ps + left, pe - 1, in, inroot + 1, ine);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    // Your code here

    Node *ans = fun(post, 0, n - 1, in, 0, n - 1);

    return ans;
}
