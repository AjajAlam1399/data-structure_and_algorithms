//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> fun( vector<vector<int>>cpy_adj){
      vector<int>ans;
      queue<int>q;
      vector<int>indegree(cpy_adj.size(),0);
      for(int i=0;i<cpy_adj.size();i++){
          for(int j=0;j<cpy_adj[i].size();j++){
              indegree[cpy_adj[i][j]]++;
          }
      }
      for(int i=0;i<indegree.size();i++){
          if(indegree[i]==0){
              q.push(i);
          }
      }
      while(!q.empty()){
          int v=q.front();
          q.pop();
          ans.push_back(v);
          for(auto it=cpy_adj[v].begin();it!=cpy_adj[v].end();it++){
              indegree[*it]--;
              if(indegree[*it]==0){
                  q.push(*it);
              }
              
          }
      }
      sort(ans.begin(),ans.end());
      return ans;
    // return indegree;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>>cpy_adj(V);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                cpy_adj[it].push_back(i);
            }
            
        }
        
        return fun(cpy_adj);
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends