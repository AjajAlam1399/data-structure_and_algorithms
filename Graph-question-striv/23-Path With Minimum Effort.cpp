#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int row=heights.size();
        int col=heights[0].size();
        
        vector<vector<int>>dist(row,vector<int>(col,1e8));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int mindist=it.first;
            int i=it.second.first;
            int j=it.second.second;
            
            int arr1[]={1,0,0,-1};
            int arr2[]={0,-1,1,0};
            
            for(int k=0;k<4;k++){
                int nrow=i+arr1[k];
                int ncol=j+arr2[k];
                
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col){
                    int currdist=abs(heights[i][j]-heights[nrow][ncol]);
                    int dis=max(mindist,currdist);
                    if(dist[nrow][ncol]>dis){
                        dist[nrow][ncol]=dis;
                        pq.push({dis,{nrow,ncol}});
                    }
                }
            }
        }
        
        return dist[row-1][col-1];
    }
};