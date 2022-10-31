//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fun(int s,vector<int>adj[],vector<bool>&visted,vector<int>&ans){
        queue<pair<int,int>>q;
         visted[0]=true;
	       ans[s]=0;
	    q.push({s,0});
	    while(!q.empty()){
	        int v=q.front().first;
	        int color=q.front().second;
	        q.pop();
	        for(auto it=adj[v].begin();it!=adj[v].end();it++){
	            if(!visted[*it]){
	                visted[*it]=true;
	                ans[*it]=!color;
	                q.push({*it,!color});
	            }
	            else{
	                if(ans[*it]==color){
	                    return false;
	                }
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    queue<pair<int,int>>q;
	    vector<bool>visted(V,false);
	    vector<int>ans(V,-1);
	    for(int i=0;i<V;i++){
	        if(!visted[i]){
	            bool flag=fun(i,adj,visted,ans);
	            if(flag==false){
	                return flag;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends