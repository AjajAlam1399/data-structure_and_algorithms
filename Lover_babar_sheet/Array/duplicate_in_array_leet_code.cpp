#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int n=nums.size();
        
        for(int i=0;i<n;i++){
            nums[nums[i]%n]+=n;
        }
        
        for(int i=0;i<n;i++){
           if( nums[i]/n>1){
               return i;
           }
        }
        return -1;
    }
};