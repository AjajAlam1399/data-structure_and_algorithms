#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>&nums,int s,int m,int e,int &count){
        int i=s;
        int j=m+1;
        
        
        while(i<=m && j<=e){
            if(nums[i]>(long long)2*nums[j]){
                count+=m-i+1;
                j++;
                
            }
            else{
                i++;
            }
        }
        sort(nums.begin()+s,nums.begin()+e+1);
        return ;
    }
    void merging_sort(vector<int>&nums,int s,int e,int &count){
        if(s==e){
            return ;
        }
            int m=(s+e)/2;
            merging_sort(nums,s,m,count);
            merging_sort(nums,m+1,e,count);
            merge(nums,s,m,e,count);
        
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
        merging_sort(nums,0,nums.size()-1,count);
        // for(auto it : nums) cout<<it<<" ";
        // cout<<endl;
        return count;
    }
};