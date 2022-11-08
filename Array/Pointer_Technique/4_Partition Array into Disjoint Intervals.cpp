#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        if(nums.size()<=2){
            return 1;
        }
        int max1=nums[0];
        int max2=max1;
        int left=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<max1){
                left=i+1;
                max1=max2;
                max2=max1;
            }
            else{
                max2=max(max2,nums[i]);
            }
        }
        return left;
    }
};