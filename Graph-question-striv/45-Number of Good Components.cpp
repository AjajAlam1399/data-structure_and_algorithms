#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool>visted(V+1,false);
        
        int cnt=0;
        
        for(int i=1;i<=V;i++){
            if(!visted[i]){
                int edgcnt=0;
                int vcnt=0;
                fun(i,adj,visted,vcnt,edgcnt);
                if(edgcnt==((vcnt)*(vcnt-1))){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void fun(int v,vector<vector<int>>&adj,vector<bool>&visted,int &vcnt,int &edgcnt){
        
        visted[v]=true;
        vcnt++;
        edgcnt+=adj[v].size();
        for(auto u : adj[v]){
            if(!visted[u]){
                
                fun(u,adj,visted,vcnt,edgcnt);
            }
        }
       
    }
};