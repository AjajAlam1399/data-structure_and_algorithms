#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                return true;
            }
        }
        
        unordered_map<int,int> m;
        
        int sum=arr[0];
        m[sum]++;
        
        for(int i=1;i<n;i++){
            sum+=arr[i];
            m[sum]++;
        }
        
        if(m[0]){
            return true;
        }
        
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>1){
                return true;
            }
        }
        
        return false;
    }
};