//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{

    Node *auxiliary(int in[], int is, int ie, int pre[], int ps, int pe)
    {
        if (ps > pe || is > ie)
            return NULL;
        int i;
        for (i = is; i <= ie; i++)
        {
            if (in[i] == pre[ps])
            {
                break;
            }
        }
        int inRoot = i;
        Node *root = new Node(pre[ps]);
        root->left = auxiliary(in, is, inRoot - 1, pre, ps + 1, inRoot + ps - is);
        root->right = auxiliary(in, inRoot + 1, ie, pre, inRoot + ps - is + 1, pe);
        return root;
    }

public:
    Node *buildTree(int in[], int pre[], int n)
    {
        Node *res = auxiliary(in, 0, n - 1, pre, 0, n - 1);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends