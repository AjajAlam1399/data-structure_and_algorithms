#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	int timer;
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        
        vector<bool>visted(V,0);
        vector<int>tim(V,0);
        vector<int>lowtim(V,0);
        
        if(c>d){
            swap(c,d);
        }
        
        for(int i=0;i<V;i++){
            if(!visted[i]){
                timer=0;
                if(dfs(i,-1,adj,visted,tim,lowtim,c,d)){
                    return 1;
                }
                
               
            }
        }
        
        return 0;
    }
    
    bool dfs(int v,int parent, vector<int>adj[],vector<bool>&visted,
    vector<int>&tim,vector<int>&low,int c,int d){
        visted[v]=true;

        low[v]=tim[v]=timer;
        timer++;

        for(auto u : adj[v]){
            if(u==parent) continue;
            else if(!visted[u]){
                if(dfs(u,v,adj,visted,tim,low,c,d)){
                    return true;
                }
                low[v]=min(low[v],low[u]);
                if(low[u]>tim[v]){
                    int first=v;
                    int second=u;
                    if(first>second){
                        swap(first,second);
                    }
                    
                    if(first==c && second==d){
                        return true;
                    }
                    
                }
            }
            else{
                low[v]=min(low[u],low[v]);
            }
        }
        
        return false;
    }
};