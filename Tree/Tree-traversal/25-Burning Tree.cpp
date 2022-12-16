//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

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
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void fun1(Node* root,unordered_map<Node*,Node*>&parent,int target,Node* &targetNode){
    queue<Node*>q;
    
    q.push(root);
    
    while(!q.empty()){
        root=q.front();
        if(root->data==target){
            targetNode=root;
        }
        q.pop();
        
        if(root->left){
            parent[root->left]=root;
            q.push(root->left);
        }
        
        if(root->right){
            parent[root->right]=root;
            q.push(root->right);
        }
    }
}
void fun(Node* root,int target,int &ans){
    
    unordered_map<Node*,Node*>parent;
    
    Node* targetNode=NULL;
    
    fun1(root,parent,target,targetNode);
    
    unordered_map<Node*,bool>visted;
    
    queue<Node*>q;
    
    q.push(targetNode);
    visted[targetNode]=true;
    
    bool flag=false;
    
    
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            root=q.front();
            q.pop();
            
            if(parent.find(root)!=parent.end() && !visted[parent[root]]){
                visted[parent[root]]=true;
                q.push(parent[root]);
                flag=true;
            }
            
            if(root->left && !visted[root->left]){
                visted[root->left]=true;
                q.push(root->left);
                flag=true;
            }
            if(root->right && !visted[root->right]){
                visted[root->right]=true;
                q.push(root->right);
                flag=true;
            }
        }
        if(flag){
            ans++;
        }
        flag=false;
    }
}
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int ans=0;
        
        fun(root,target,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends