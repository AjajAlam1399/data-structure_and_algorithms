#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>parent(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        vector<int>dist(n+1,1e7);
        
        dist[1]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int srcdist=pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(dist[adjnode]>srcdist+w){
                    dist[adjnode]=srcdist+w;
                    parent[adjnode]=node;
                    pq.push({srcdist+w,adjnode});
                }
            }
        }
        
        vector<int>ans;
        
        if(dist[n]==1e7){
            return {-1};
        }
        
        int temp=n;
        
        while(parent[temp]!=temp){
            ans.push_back(temp);
            temp=parent[temp];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};