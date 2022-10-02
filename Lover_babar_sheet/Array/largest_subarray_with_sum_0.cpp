#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        
        
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            sum+=A[i];
            auto it=m.find(sum);
            if(it!=m.end()){
                
                ans=max(ans,i-it->second);
            }
            else{
                m[sum]=i;
            }
        }
        return ans;
    }
};