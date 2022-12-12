#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(vector<int>arr,int tar,int ind,vector<int>ans,vector<vector<int>>&result){
       if(tar==0){
           result.push_back(ans);
           return;
       }

       for(int i=ind;i<arr.size();i++){
           if(i>ind && arr[i]==arr[i-1]) continue;
           if(arr[i]>tar) break;
           ans.push_back(arr[i]);
           fun(arr,tar-arr[i],i+1,ans,result);
           ans.pop_back();
       }
       return ;
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());

        vector<vector<int>>result;
        vector<int>ans;

        

        fun(candidates,target,0,ans,result);

        
        return result;
    }
};