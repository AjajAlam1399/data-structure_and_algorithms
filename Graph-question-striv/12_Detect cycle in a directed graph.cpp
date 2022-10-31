//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool fun(int s,vector<int> adj[],vector<bool>&visted,vector<bool>&pathVisted){
        visted[s]=true;
        pathVisted[s]=true;
        
        for(auto it : adj[s]){
            if(!visted[it]){
                if(fun(it,adj,visted,pathVisted)==true){
                    return true;
                }
            }
            else if(pathVisted[it]){
                return true;
            }
        }
        
        pathVisted[s]=false;
        return false;
        
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visted(V,false);
        vector<bool>pathvisted(V,false);
        for(int i=0;i<V;i++){
            if(!visted[i]){
                bool flag=fun(i,adj,visted,pathvisted);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends