//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution
{
    unordered_map<string, int> map;
    vector<Node *> ans;

public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root)
    {
        // code here

        fun(root);

        if (ans.size() >= 1)
        {
            Node *temp = ans.back();
            int currsize = height(temp);
            if (currsize >= 2)
            {
                return true;
            }
        }
        return false;
    }

    string fun(Node *root)
    {
        if (root == NULL)
        {
            return "#";
        }
        string s = fun(root->left) + fun(root->right) + to_string(root->data);
        map[s]++;
        if (map[s] == 2)
        {

            ans.push_back(root);
        }
        return s;
    }
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        return max(l, r) + 1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    // cout << t << "\n";
    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.dupSub(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends