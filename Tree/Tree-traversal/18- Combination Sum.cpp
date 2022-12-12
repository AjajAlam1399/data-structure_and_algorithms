#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   void fun(vector<int>arr,int tar,int i,vector<int>ans,set<vector<int>>&result){
       if(tar==0){
           result.insert(ans);
           return;
       }

       if(i==arr.size()){
           return ;
       }

       fun(arr,tar,i+1,ans,result);

       if(tar>=arr[i]){
           ans.push_back(arr[i]);
           fun(arr,tar-arr[i],i,ans,result);
           ans.pop_back();
       }

       return ;

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>result;
        vector<int>ans;

        

        fun(candidates,target,0,ans,result);

        vector<vector<int>>res;
        res.insert(res.end(),result.begin(),result.end());
        return res;
    }
};