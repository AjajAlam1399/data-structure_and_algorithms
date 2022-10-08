#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<tuple<int,int,int>>set;
        vector<vector<int>>result;
        
        long a,b,sum,s,e,t,i1,i2,k;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            a=nums[i];
            t=-a;
            s=i+1;
            e=nums.size()-1;
            while(s<e){
                sum=(long long)nums[s]+nums[e];
                if(sum==t){
                    set.emplace(make_tuple(a,nums[s],nums[e]));
                    k=s;
                    i1=s+1;
                    while(i1!=e && nums[s]==nums[i1]){
                        i1++;
                    }
                    s=i1;
                    i2=e-1;
                    while(i2!=k && nums[e]==nums[i2]){
                        i2--;
                    }
                    e=i2;
                }
                else if(sum>t){
                    e--;
                }
                else if(sum<t){
                    s++;
                }
            }
        }
        for(auto it=set.begin();it!=set.end();it++){
            result.push_back({get<0>(*it),get<1>(*it),get<2>(*it)});
        }
        return result;
    }
};