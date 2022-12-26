#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable=0;

        for(int i=0;i<nums.size();i++){
            if(i>reachable){
                return false;
            }
            reachable=max(reachable,nums[i]+i);
        }

        return true;
    }
};