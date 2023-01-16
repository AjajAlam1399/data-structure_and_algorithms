#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
         int n=intervals.size();
         
         sort(intervals.begin(),intervals.end());
         
         stack<pair<int,int>>st;
         st.push({intervals[0][0],intervals[0][1]});
         
         for(int i=0;i<n;i++){
             auto it=st.top();
             st.pop();
             if(it.second<intervals[i][0]){
                 st.push(it);
                 st.push({intervals[i][0],intervals[i][1]});
             }
             else{
                 int first=min(it.first,intervals[i][0]);
                 int second=max(it.second,intervals[i][1]);
                 
                 st.push({first,second});
             }
         }
         vector<vector<int>>ans;
         
         while(!st.empty()){
             auto it=st.top();
             st.pop();
             ans.push_back({it.first,it.second});
         }
         
         sort(ans.begin(),ans.end());
         
         return ans;
    }
};