#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    vector<int>adj[N];
    vector<int>badj[N];
    for(int i=0;i<N;i++){
        if(Edge[i]!=-1){
            adj[i].push_back(Edge[i]);
            badj[Edge[i]].push_back(i);
        }
    }
    vector<bool>visted(N,false);
    
    stack<int>st;
    
    for(int i=0;i<N;i++){
        if(!visted[i]){
            dfs(i,adj,visted,st);
        }
    }
    
    vector<bool>visted2(N,false);
    
    int ans=-1;
    while(!st.empty()){
        vector<int>list;
        int v=st.top();
        st.pop();
        if(!visted2[v]){
            dfs1(v,badj,visted2,list);
            if(list.size()>1){
                int currans=accumulate(list.begin(),list.end(),0);
                ans=max(ans,currans);
            }
        }
    }
    return ans;
    
  }
  void dfs(int v,vector<int>adj[],vector<bool>&visted,stack<int>&st){
      visted[v]=true;
      
      for(auto u : adj[v]){
          if(!visted[u]){
              dfs(u,adj,visted,st);
          }
      }
      st.push(v);
  }
  void dfs1(int v,vector<int>adj[],vector<bool>&visted,vector<int>&list){
      visted[v]=true;
      
      for(auto u : adj[v]){
          if(!visted[u]){
              dfs1(u,adj,visted,list);
          }
      }
      list.push_back(v);
  }
 
};