#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
        }
        if(count==0){
            return 0;
        }
        vector<int>v(nums.begin(),nums.end());
        v.insert(v.end(),nums.begin(),nums.end());
        
        int n=v.size();
        int e=0,s=0;
        int sum=0;
        int result=INT_MAX;
        while(e<n){
            sum+=v[e];
            if(e-s+1<count){
                e++;
            }
            else if(e-s+1==count){
                result=min(result,count-sum);
                sum-=v[s];
                s++;
                e++;
            }
        }
        
        return result;
        
    }
};