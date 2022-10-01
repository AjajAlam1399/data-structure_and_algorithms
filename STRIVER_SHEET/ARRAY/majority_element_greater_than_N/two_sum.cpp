#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        
       unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++){
            if(m[target-nums[i]]){
                auto it=m.find(target-nums[i]);
                if(it->second!=i){
                    result.push_back(i);
                result.push_back(it->second);
                    break;
                }
                
            }
        }
        return result;
        
    }
};