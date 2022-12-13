#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(vector<int>&nums,int ind,vector<int>ans,vector<vector<int>>&result)
    {
       result.push_back(ans);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            fun(nums,i+1,ans,result);
            ans.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>>subans;

        fun(nums,0,ans,subans);

        return subans;
    }
};