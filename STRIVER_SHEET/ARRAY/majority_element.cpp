#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_element;
        
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        int size=nums.size()/2;
        
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>size){
                maj_element=it->first;
                break;
            }
        }
        return maj_element;
    }
};