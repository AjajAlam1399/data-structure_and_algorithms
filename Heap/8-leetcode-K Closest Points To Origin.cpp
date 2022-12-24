#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,pair<int,int>>>pq;

        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            double dist=sqrt(pow(x,2)+pow(y,2));

            if(pq.size()<k){
                pq.push({dist,{x,y}});
            }
            else{
                if(pq.top().first>dist){
                    pq.pop();
                    pq.push({dist,{x,y}});
                }
            }
        }
        vector<vector<int>>ans;
        
        while(!pq.empty()){
            vector<int>subans;
            subans.push_back(pq.top().second.first);
            subans.push_back(pq.top().second.second);
            ans.push_back(subans);
            
            pq.pop();
        }
        return ans;
    }
};