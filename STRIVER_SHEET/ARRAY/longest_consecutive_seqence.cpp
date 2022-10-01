#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
        set<int>s(nums.begin(),nums.end());
        vector<int>v(s.begin(),s.end());
        
        int count=1;
        int result=1;
        for(int i=1;i<=v.size()-1;i++){
            if(v[i]-1==v[i-1]){
                count++;
                result=max(result,count);
            }
            else{
                count=1;
            }
        }
        return result;
    }
};