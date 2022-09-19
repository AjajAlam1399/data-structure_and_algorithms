#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        multiset<int>s(nums1.begin(),nums1.end());
        
        s.insert(nums2.begin(),nums2.end());
        
        vector<int>v(s.begin(),s.end());
        
        int size=v.size();
        
        int index;
        
        if(size%2!=0){
            index=(size+1)/2;
            
            return v[index-1];
        }
        else{
            index=size/2;
            
            double sum = (v[index]+v[index-1]);
            return sum/2;
        }
        
    }
};