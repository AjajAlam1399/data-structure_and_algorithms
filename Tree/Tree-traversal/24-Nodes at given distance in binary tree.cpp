//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

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
void fun(Node* root,int target,int k,vector<int>&ans){
    
    unordered_map<Node*,Node*>parent;
    
    Node* targetNode=NULL;
    
    fun1(root,parent,target,targetNode);
    
    unordered_map<Node*,bool>visted;
    
    queue<Node*>q;
    
    q.push(targetNode);
    visted[targetNode]=true;
    
    int distance=0;
    
    while(!q.empty()){
        int size=q.size();
        if(distance==k){
            break;
        }
        for(int i=0;i<size;i++){
            root=q.front();
            q.pop();
            
            if(parent.find(root)!=parent.end() && !visted[parent[root]]){
                visted[parent[root]]=true;
                q.push(parent[root]);
            }
            
            if(root->left && !visted[root->left]){
                visted[root->left]=true;
                q.push(root->left);
            }
            if(root->right && !visted[root->right]){
                visted[root->right]=true;
                q.push(root->right);
            }
        }
        distance++;
    }
    
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }
    sort(ans.begin(),ans.end());
}
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;
        
        fun(root,target,k,ans);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends