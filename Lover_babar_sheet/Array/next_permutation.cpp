#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int> &nums)
{
        int first=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                first=i;
                break;
            }
        }
        if(first==-1){
            reverse(nums.begin(),nums.end());
            for(auto i : nums) cout<<i<<" ";
            return;
        }
        int second=first;
        
        for(int i=first+1;i<nums.size();i++){
            if(nums[i]>nums[first-1] && nums[i]<=nums[second] ){
                
                second=i;
            }
        }
        
        swap(nums[first-1],nums[second]);
        reverse(nums.begin()+first,nums.end());
        for(auto i :nums) cout<<i<<" ";
    }
};