//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
   vector<int> fun(vector<vector<int>>adj_list){
        vector<int>ans;
        vector<int>indegree(adj_list.size(),0);
        for(int i=0;i<adj_list.size();i++){
            for(auto it : adj_list[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ans.push_back(v);
            for(auto it : adj_list[v]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector<vector<int>>adj_list(n);
	    for(auto it :  prerequisites){
	        adj_list[it[1]].push_back(it[0]);
	    }
	    vector<int>result=fun(adj_list);
	    if(result.size()==adj_list.size()){
	        return result;
	    }
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends