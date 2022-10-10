#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int s=0;
        int n=nums.size();
        int e=n-1;
        int prev;
        int next;
        
        while(s<=e){
            if(nums[s]<=nums[e]){
                return nums[s];
            }
            int mid=s+(e-s)/2;
            prev=(mid-1+n)%n;
            next=(mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            else if(nums[mid]>=nums[s]){
                s=mid+1;
            }
            else if(nums[mid]<=nums[e]){
                e=mid-1;
            }
        }
        return -1;
        
    }
};