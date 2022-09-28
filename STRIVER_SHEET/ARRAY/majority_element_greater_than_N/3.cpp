#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        int size=nums.size()/3;
        
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>size){
                v.push_back(it->first);
            }
        }
        return v;
    
    }
};