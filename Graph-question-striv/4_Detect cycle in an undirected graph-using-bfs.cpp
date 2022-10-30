//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int src,vector<int>adj[],vector<bool>&visted){
        queue<pair<int,int>>q;
        q.push(make_pair(src,-1));
        visted[src]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it=adj[node].begin();it!=adj[node].end();it++){
                if(!visted[*it]){
                    visted[*it]=true;
                    q.push(make_pair(*it,node));
                }
                else if(*it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector<bool>visted(V,false);
       bool ans=false;
       for(int i=0;i<V;i++){
           if(!visted[i]){
                ans=bfs(i,adj,visted);
                if(ans==true){
                    return ans;
                }
           }
       }
       return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends