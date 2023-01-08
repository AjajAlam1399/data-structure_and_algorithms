#include<bits/stdc++.h>
using namespace std;
#define ln long long int
class Solution {
  public:
    long long subarrayRanges(int N, vector<int> &nums) {
        // code here
        
        int n=nums.size();
        
        ln ans=0;

        for(int i=0;i<n;i++){
            int min_e=INT_MAX;
            int max_e=INT_MIN;
            for(int j=i;j<n;j++){
                if(min_e>nums[j]){
                    min_e=nums[j];
                }
                if(max_e<nums[j]){
                    max_e=nums[j];
                }

                ans+=(max_e-min_e);
            }
        }
        return ans;
        
    }
};